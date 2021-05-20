/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    long res = 0;

    for (; (res * res) < nb; res++);
    if ((res * res) > nb)
        res = 0;
    if (res > 2147483647)
        return (0);
    return (res);
}
