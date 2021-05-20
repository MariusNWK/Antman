/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/
#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
