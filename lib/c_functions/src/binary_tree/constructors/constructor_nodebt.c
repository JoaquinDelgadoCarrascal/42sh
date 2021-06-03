/*
** EPITECH PROJECT, 2021
** constructor_nodebt.c
** File description:
** constructor_nodebt.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "c_functions_structures.h"

t_nodebt *constructor_nodebt(char *value, t_nodebt *parent)
{
    t_nodebt *new_node = malloc(sizeof(t_nodebt));

    new_node->value = my_strdup(value);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = parent;
    free(value);
    return (new_node);
}