/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/
#include "my.h"
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
}
