/*
** EPITECH PROJECT, 2021
** is_pipe.c
** File description:
** is_pipe.c
*/

#include "c_functions.h"
#include "c_functions_structures.h"

bool is_pipe(t_nodebt *node)
{
    return (my_strcmp(node->value, "|") == 0);
}