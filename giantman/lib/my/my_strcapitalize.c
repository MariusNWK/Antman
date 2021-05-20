/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65  && str[i] <= 90)
            if (str[i - 1] != ' ' || str[i - 1] != '+' || str[i - 1] != '-')
                str[i] = str[i] + 32;
        if ((str[i] >= 97 && str[i] <= 122) && (i == 0 || str[i - 1] ==
            ' ' || str[i - 1] == '+' || str[i - 1] == '-'))
            str[i] = str[i] - 32;
    }
    return (str);
}
