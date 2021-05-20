/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    long res = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    res = nb * (my_compute_power_rec(nb, p - 1));
    if (res < -2147483648 || res > 2147483647)
        return (0);
    return (res);
}
