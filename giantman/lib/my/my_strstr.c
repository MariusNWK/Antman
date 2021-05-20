/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my_strstr
*/
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int la = 0;

    for (; to_find[la] != '\0'; la++);
    la = la - 1;
    for (; *str != '\0'; *str++)
        for (i = 0, j = 0; str[i] == to_find[j] && str[j] != '\0'; j++, i++)
            if (j == la) {
                my_putstr(str);
                return (str);
            }
    my_putstr(str);
    return (str);
}
