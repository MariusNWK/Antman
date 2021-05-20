/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** task 3
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int j = 0;

    while (dest[j] != '\0')
        j++;
    for (int i = 0; src[i] != '\0' && i < nb; i++, j++) {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    return (dest);
}
