/*
** EPITECH PROJECT, 2021
** antman
** File description:
** antman
*/
#include <unistd.h>
#include "my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84) {
        return (84);
    }
    lzw_algo(av[1]);
    return (0);
}