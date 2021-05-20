/*
** EPITECH PROJECT, 2021
** tools
** File description:
** antman
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

list_t *set_basic_entry(list_t *chars)
{
    infos_t info;

    for (int i = 0, len = len_list(chars); i < len; i++) {
        info = get_at(chars, i);
        info.index = i;
        info.entry = malloc(sizeof(char) * 2);
        info.entry[0] = info.c;
        info.entry[1] = '\0';
        set_at(chars, info, i);
    }
    return (chars);
}

void free_entry(list_t *chars)
{
    infos_t info;

    for (int i = 0, len = len_list(chars); i < len - 1; i++) {
        info = get_at(chars, i);
        free(info.entry);
    }
}

char *find_new_entry(list_t *chars, char *comb, char *file, int k)
{
    int len_comb = my_strlen(comb);
    infos_t info;

    for (int i = 0, len = len_list(chars); i < len; i++) {
        info = get_at(chars, i);
        if (is_same_str(comb, info.entry) == 1) {
            comb = my_realloc(comb, len_comb + 2);
            if (file[k + len_comb] == '\0') {
                comb[len_comb] = 'k';
                comb[len_comb + 1] = '\0';
            }
            else {
                comb[len_comb] = file[k + len_comb];
                comb[len_comb + 1] = '\0';
                return (find_new_entry(chars, comb, file, k));
            }
        }
    }
    return (comb);
}

int display_dictionnary(list_t *chars)
{
    int len = len_list(chars);
    infos_t info;

    for (int i = 0; i < len; i++) {
        info = get_at(chars, i);
        write(1, &info.c, 1);
    }
    write(1, "\0", 1);
    return (len);
}