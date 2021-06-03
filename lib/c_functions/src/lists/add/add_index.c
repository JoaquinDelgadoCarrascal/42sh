/*
** EPITECH PROJECT, 2021
** add_index.c
** File description:
** add_index.c
*/

#include <stddef.h>
#include "c_functions.h"

t_list *do_add_index(t_list *list, t_nodell *new_node, int index)
{
    t_nodell *head = NULL;
    t_nodell *tmp = NULL;

    head = list->head;
    for (int i = 0; i < index - 2; i++) {
        list->head = list->head->next;
    }
    tmp = list->head->next;
    list->head->next = new_node;
    list->head->next->prev = list->head;
    list->head->next->next = tmp;
    list->head = head;
    list->size += 1;
    return (list);
}

t_list *add_index(t_list *list, t_nodell *new_node, int index)
{
    if (list == NULL)
        return (NULL);
    if (list->head == NULL) {
        list = add_end(list, new_node);
        return (list);
    }
    if (index == 0 || index == 1) {
        list = add_start(list, new_node);
        return (list);
    }
    return (do_add_index(list, new_node, index));
}