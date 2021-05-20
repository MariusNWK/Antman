/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** task 2
*/

char *my_strcat(char *dest, char const *src)
{
    int j = 0;

    while (dest[j] != '\0')
        j++;
    for (int i = 0; src[i] != '\0'; i++, j++) {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    return (dest);
}
