/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** antman
*/
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "my.h"

int check_system_functions(char *file)
{
    int fd = open(file, O_RDONLY);
    char *str;

    if (fd == -1) {
        return (84);
    }
    str = malloc(getfilesize(file) + 1);
    if (str == NULL) {
        return (84);
    }
    if (read(fd, str, getfilesize(file)) == -1) {
        return (84);
    }
    close(fd);
    return (0);
}

int error_handling(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Invalid number of arguments\n", 28);
        return (84);
    }
    if (getfilesize(av[1]) == 0) {
        write(2, "Invalid file\n", 13);
        return (84);
    }
    if (my_strlen(av[2]) != 1) {
        write(2, "Invalid file type\n", 18);
        return (84);
    }
    if (av[2][0] != '1' && av[2][0] != '2' && av[2][0] != '3') {
        write(2, "Invalid file type\n", 18);
        return (84);
    }
    if (check_system_functions(av[1]) == 84) {
        write(2, "Read, Open or Malloc crahsed\n", 29);
        return (84);
    }
    return (0);
}