/*
** EPITECH PROJECT, 2021
** list2
** File description:
** antman
*/
#include "my.h"
#include <stdlib.h>

infos_t get_at(list_t *list, int pos)
{
    int i = 0;

    while (i < pos) {
        i++;
        list = list->next;
    }
    return (list->data);
}

void set_at(list_t *list, infos_t data, int pos)
{
    int i = 0;

    if (is_empty_list(list)) {
        return;
    }
    while (i < pos) {
        i++;
        list = list->next;
    }
    list->data = data;
}

list_t *free_at(list_t *list, int pos)
{
    list_t *prec = list;
    list_t *cur = list;
    int i = 0;

    if (is_empty_list(list)) {
        return (NULL);
    }
    if (pos == 0) {
        list = list->next;
        free(cur);
        return (list);
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cur->next;
    free(cur);
    return (list);
}

list_t *move_at(list_t *list, int pos_i, int pos_f)
{
    infos_t info = get_at(list, pos_i);

    list = free_at(list, pos_i);
    list = add_at(list, info, pos_f);
    return (list);
}