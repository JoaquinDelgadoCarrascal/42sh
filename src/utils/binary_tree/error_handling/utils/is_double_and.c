/*
** EPITECH PROJECT, 2021
** is_double_and.c
** File description:
** is_double_and.c
*/

#include "c_functions.h"

bool is_double_and(t_nodebt *node)
{
    return (my_strcmp(node->value, "&&") == 0);
}