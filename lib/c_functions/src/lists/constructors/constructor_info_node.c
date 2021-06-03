/*
** EPITECH PROJECT, 2021
** constructor_info_node.c
** File description:
** constructor_info_node.c
*/

#include <stdlib.h>
#include "c_functions_structures.h"

t_info_node *constructor_info_node(char *var_name, char *var_value)
{
    t_info_node *new_info_node = malloc(sizeof(t_info_node));

    if (!new_info_node)
        return (NULL);
    new_info_node->var_name = var_name;
    new_info_node->var_value = var_value;
    return (new_info_node);
}