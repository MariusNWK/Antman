/*
** EPITECH PROJECT, 2021
** output_last_char
** File description:
** antman
*/
#include "my.h"

list_t *output_last_char(list_t *chars, char *file, int i)
{
    infos_t info;

    for (int j = 0, len = len_list(chars); j < len; j++) {
        if (get_at(chars, j).c == file[i]) {
            info.output = get_at(chars, j).index;
            chars = add_at(chars, info, len);
            break;
        }
    }
    return (chars);
}