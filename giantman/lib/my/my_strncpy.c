/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int m = 0;
    int i = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        m++;
    }
    i = 0;
    if (n >= m)
        for (; i <= m; i++)
            dest[i] = src[i];
    else
        for (; i < n; i++)
            dest[i] = src[i];
    return (dest);
}
