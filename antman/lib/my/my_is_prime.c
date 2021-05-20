/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int res = 0;

    for (int i = 1; i <= nb; i++)
        if (nb % i == 0)
            res++;
    if (res == 2)
        return (1);
    else
        return (0);
}
