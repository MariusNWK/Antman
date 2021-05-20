/*
** EPITECH PROJECT, 2021
** lzw decompress
** File description:
** giantman
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

list_t *set_single_entry_and_outputs(char *file)
{
    list_t *chars = NULL;
    infos_t info = {0, -1, -1};
    unsigned char c = 0;
    int i = 0;

    for (; file[i] != '\0'; i++) {
        info.entry = malloc(sizeof(char) * 2);
        info.entry[0] = file[i];
        info.entry[1] = '\0';
        info.index = i;
        chars = add_at(chars, info, i);
    }
    i++;
    for (int pos = i - 1; file[i] != '\0'; i = i + 2, pos++) {
        c = file[i];
        info.input = c * 255 - 255;
        c = file[i + 1];
        info.input += c - 1;
        info.index = pos;
        chars = add_at(chars, info, pos);
    } return (chars);
}

int skip_dictionnary(char *file)
{
    int i = 0;

    while (file[i] != '\0') {
        i++;
    }
    return (i);
}

void free_entry(list_t *chars)
{
    infos_t info;

    for (int i = 0, len = len_list(chars); i < len - 1; i++) {
        info = get_at(chars, i);
        free(info.entry);
    }
}

void lzw_decompress_algo(const char *filepath)
{
    char *file = file_reader(filepath);
    list_t *chars = set_single_entry_and_outputs(file);
    int start = skip_dictionnary(file);

    display_decompressed(chars, start);
    free_entry(chars);
    free_list(chars);
    free(file);
}