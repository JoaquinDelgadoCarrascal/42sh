/*
** EPITECH PROJECT, 2021
** constructor_node.c
** File description:
** constructor_node.c
*/

#include <stdlib.h>
#include "c_functions_structures.h"

t_nodell *constructor_node(t_info_node *info)
{
    t_nodell *new_node = malloc(sizeof(t_nodell));

    if (!new_node)
        return (NULL);
    new_node->info = info;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}