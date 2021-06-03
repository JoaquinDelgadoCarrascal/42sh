/*
** EPITECH PROJECT, 2021
** is_double_or.c
** File description:
** is_double_or.c
*/

#include "c_functions.h"

bool is_double_or(t_nodebt *node)
{
    return (my_strcmp(node->value, "||") == 0);
}