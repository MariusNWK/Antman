/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int n;
    int m;

    n = *a;
    m = *b;
    *a = m;
    *b = n;
}
