/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** my_putnbr
*/
#include "my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    int i = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 12);
        return (0);
    }
    if (nb < 0) {
        nb = nb * (-1);
        write(1, "-", 1);
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    i = nb % 10 + 48;
    write(1, &i, 1);
    return (0);
}
