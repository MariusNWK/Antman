/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++)
        n++;
    return (n);
}
