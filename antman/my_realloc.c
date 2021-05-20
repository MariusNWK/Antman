/*
** EPITECH PROJECT, 2021
** my_realloc
** File description:
** antman
*/
#include <stdlib.h>

char *my_realloc(char *str, int size)
{
    char *dest = malloc(sizeof(char) * size);
    int i = 0;

    for (; str[i] != '\0'; i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    free(str);
    return (dest);
}