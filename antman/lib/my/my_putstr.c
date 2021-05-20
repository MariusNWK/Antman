/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
