/*
** EPITECH PROJECT, 2021
** delete_start.c
** File description:
** delete_start.c
*/

#include <stddef.h>
#include "c_functions.h"

t_list *delete_start(t_list *list)
{
    t_nodell *next_nodell = NULL;

    if (list == NULL || list->size == 0)
        return (NULL);
    if (list->size == 1) {
        free_list(list);
        return (NULL);
    }
    if (list->head != NULL) {
        next_nodell = list->head->next;
        free_node(list->head);
        list->head = next_nodell;
        list->head->prev = NULL;
        list->size -= 1;
        return (list);
    }
}