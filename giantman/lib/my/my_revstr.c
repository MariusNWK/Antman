/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int j = 0;
    int k = 0;
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        j = i;
        k = i;
    }
    for (int i = 0; i <= (j / 2); i++, k--) {
        a = str[i];
        str[i] = str[k];
        str[k] = a;
    }
    return (str);
}
