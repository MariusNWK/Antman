/*
** EPITECH PROJECT, 2021
** display_compressed
** File description:
** giantman
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *copy_entry(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return (dest);
}

char *add_char_nextoutput(char *dest, char c, int size)
{
    dest[size - 1] = c;
    dest[size] = '\0';
    return (dest);
}

void display_decompressed(list_t *chars, int start)
{
    infos_t info;
    infos_t n_info;
    int size = 0;

    for (int i = start, len = len_list(chars); i < len - 1; i++) {
        info = get_at(chars, i);
        size = my_strlen(get_at(chars, info.input).entry) + 1;
        info.entry = malloc(sizeof(char) * size + 1);
        info.entry = copy_entry(info.entry, get_at(chars, info.input).entry);
        set_at(chars, info, i);
        n_info = get_at(chars, i + 1);
        info.entry = add_char_nextoutput(info.entry,
            get_at(chars, n_info.input).entry[0], size);
        set_at(chars, info, i);
    }
    for (int i = start, len = len_list(chars); i < len; i++) {
        info = get_at(chars, i);
        my_putstr(get_at(chars, info.input).entry);
    }
}