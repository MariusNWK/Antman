/*
** EPITECH PROJECT, 2021
** test
** File description:
** antman
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "my.h"

size_t getfilesize(char const *filepath)
{
    struct stat st;

    if (stat(filepath, &st) != 0)
        return (0);
    return (st.st_size);
}

char *file_reader(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str;

    str = malloc(getfilesize(filepath) + 1);
    read(fd, str, getfilesize(filepath));
    str[getfilesize(filepath)] = '\0';
    close(fd);
    return (str);
}

void compare_size(char *file, char *compressed)
{
    int size_file = getfilesize(file);
    int size_comp = getfilesize(compressed);

    my_putstr("The base file size : ");
    my_put_nbr(size_file);
    my_putstr("\nThe compressed file size : ");
    my_put_nbr(size_comp);
    my_putstr("\nThe compress size percentage is : ");
    my_put_nbr(100.0 - (((float)size_comp / (float)size_file) * 100.0));
    my_putstr("%\n");
}

void compare_str(char *file, char *decompressed)
{
    my_putstr("\n\nThe base and decompressed files are : ");
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] != decompressed[i]) {
            my_putstr("Differents\n\n");
            return;
        }
    }
    my_putstr("Identical\n\n");
}

int main(int ac, char **av)
{
    if (ac != 4) {
        write(2, "Use test.sh\n", 12);
        return (84);
    }
    my_putstr("**************************TEST******************************\n");
    compare_str(file_reader(av[1]), file_reader(av[3]));
    compare_size(av[1], av[2]);
    return (0);
}
