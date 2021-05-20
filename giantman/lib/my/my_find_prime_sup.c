/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    int prem = 0;

    while (my_is_prime(nb) != 1) {
        nb++;
    }
    return (nb);
}
