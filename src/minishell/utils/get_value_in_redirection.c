/*
** EPITECH PROJECT, 2021
** get_value_in_redirection.c
** File description:
** get_value_in_redirection.c
*/

#include "c_functions.h"

char *get_value_in_redirection(t_nodebt *node)
{
    if (my_strcmp(node->right->value, "|") != 0)
        return (node->right->value);
    return (node->right->left->value);
}