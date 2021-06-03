/*
** EPITECH PROJECT, 2021
** free_node.c
** File description:
** free_node.c
*/

#include <stdlib.h>
#include "c_functions_structures.h"

void free_node(t_nodell *node)
{
    if (node->info->var_name)
        free(node->info->var_name);
    if (node->info->var_value)
        free(node->info->var_value);
    free(node->info);
    free(node);
}