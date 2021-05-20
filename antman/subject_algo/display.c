/*
** EPITECH PROJECT, 2021
** display_unique
** File description:
** antman
*/
#include "my.h"

void display_unique(int words_nbr, char **words, int *sizes)
{
    for (int i = 0; i < words_nbr; i++) {
        if (sizes[i] > 0) {
            my_putstr(words[i]);
            my_putchar(' ');
        }
    }
}

void display_values(int words_nbr, char **words, int *sizes)
{
    for (int i = 0; i < words_nbr; i++) {
        for (int j = 0, k = 0, found = 0; j < words_nbr && found == 0; j++) {
            if (sizes[j] > 0) {
                if (is_same_str(words[i], words[j]) == 1) {
                    my_putstr(int_to_str_converter(k));
                    my_putchar('_');
                }
                k++;
            }
        }
    }
    my_putchar('\n');
}