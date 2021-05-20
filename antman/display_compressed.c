/*
** EPITECH PROJECT, 2021
** display compressed
** File description:
** antman
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *set_output(char *comb)
{
    int len_comb = my_strlen(comb);
    char *comb_to_output = malloc(sizeof(char) * len_comb);

    for (int i = 0; i <= len_comb - 1; i++) {
        if (i == len_comb - 1) {
            comb_to_output[i] = '\0';
        }
        else {
            comb_to_output[i] = comb[i];
        }
    }
    return (comb_to_output);
}

list_t *add_new_index(list_t *chars, char *comb, int index)
{
    infos_t info = {0, 0, index, -1, my_strdup(comb)};
    infos_t info_entry;
    int len = len_list(chars);
    char *comb_to_output = set_output(comb);

    for (int i = 0; i < len; i++) {
        info_entry = get_at(chars, i);
        if (is_same_str(info_entry.entry, comb_to_output) == 1) {
            info.output = info_entry.index;
            break;
        }
    }
    chars = add_at(chars, info, len);
    free(comb_to_output);
    free(comb);
    return (chars);
}

void display_output(list_t *chars, int start)
{
    infos_t info;
    char c = 0;

    for (int i = start, len = len_list(chars); i < len; i++) {
        info = get_at(chars, i);
        c = info.output / 255 + 1;
        write(1, &c, 1);
        c = info.output % 255 + 1;
        write(1, &c, 1);
    }
    write(1, "\0", 1);
}

char *set_comb(char *file, int i, list_t *chars)
{
    char *comb;

    comb = malloc(sizeof(char) * 3);
    comb[0] = file[i];
    comb[1] = file[i + 1];
    comb[2] = '\0';
    comb = find_new_entry(chars, comb, file, i);
    return (comb);
}

list_t *display_compressed(list_t *chars, char *file)
{
    char *comb;
    infos_t info;
    int start = 0;

    start = display_dictionnary(chars);
    chars = set_basic_entry(chars);
    for (int i = 0, index = len_list(chars); file[i] != '\0'; index++) {
        if (file[i + 1] == '\0') {
            chars = output_last_char(chars, file, i);
            break;
        }
        comb = set_comb(file, i, chars);
        i = i + my_strlen(comb) - 1;
        chars = add_new_index(chars, comb, index);
    }
    display_output(chars, start);
    free_entry(chars);
    return (chars);
}