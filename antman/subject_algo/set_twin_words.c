/*
** EPITECH PROJECT, 2021
** display_compressed
** File description:
** antman
*/
#include <stdio.h>
#include "my.h"

int is_same_str(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2)) {
        return (0);
    }
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return (0);
        }
    }
    return (1);
}

int *set_twin_words(int words_nbr, char **words, int *sizes)
{
    for (int i = 0; i < words_nbr; i++) {
        for (int j = 0, same = 0; j < words_nbr && sizes[i] > 0; j++) {
            if (is_same_str(words[i], words[j]) == 1) {
                same++;
                if (same > 1) {
                    sizes[j] = 0;
                }
            }
        }
    }
    return (sizes);
}