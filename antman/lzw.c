/*
** EPITECH PROJECT, 2021
** song_lyrics_algo
** File description:
** antman
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int is_char_in_list(list_t *list, char c)
{
    list_t *course = list;

    while (course != NULL) {
        if (course->data.c == c)
            return (1);
        course = course->next;
    }
    return (0);
}

list_t *set_index_chars(list_t *chars, int len)
{
    int highest_freq = 0;
    infos_t info;

    for (int index = 0; index < len; index++) {
        for (int i = 0; i < len - index; i++) {
            info = get_at(chars, i);
            if (info.freq > highest_freq)
                highest_freq = info.freq;
        }
        for (int i = 0; i < len - index; i++) {
            info = get_at(chars, i);
            if (highest_freq == info.freq) {
                info.index = index;
                set_at(chars, info, i);
                chars = move_at(chars, i, len - 1);
                highest_freq = 0;
                i = len;
            }
        }
    }
    return (chars);
}

list_t *set_single_chars(char *text)
{
    list_t *chars = NULL;
    infos_t info = {0, 0, 0, -1};
    int len = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (is_char_in_list(chars, text[i]) == 0) {
            info.c = text[i];
            chars = add_at(chars, info, 0);
        }
    }
    len = len_list(chars);
    for (int i = 0; i < len; i++) {
        info = get_at(chars, i);
        for (int j = 0; text[j] != '\0'; j++) {
            if (info.c == text[j])
                info.freq++;
        }
        set_at(chars, info, i);
    }
    chars = set_index_chars(chars, len);
    return (chars);
}

void lzw_algo(const char *filepath)
{
    char *file = file_reader(filepath);
    list_t *chars = set_single_chars(file);
    infos_t info;

    chars = display_compressed(chars, file);
    free_list(chars);
    free(file);
}
