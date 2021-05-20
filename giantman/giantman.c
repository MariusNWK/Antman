/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** giantman
*/
#include "my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84) {
        return (84);
    }
    lzw_decompress_algo(av[1]);
    return (0);
}