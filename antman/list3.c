/*
** EPITECH PROJECT, 2021
** list3
** File description:
** antman
*/
#include "my.h"
#include <stdlib.h>

list_t *free_list(list_t *list)
{
    list_t *tmp = NULL;

    while (list) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return (list);
}

void print_list(list_t *list)
{
    while (list) {
        my_putchar(list->data.c);
        my_put_nbr(list->data.freq);
        my_putchar(' ');
        list = list->next;
    }
}