/*
** EPITECH PROJECT, 2021
** is_semicolon.c
** File description:
** is_semicolon.c
*/

#include "c_functions.h"
#include "c_functions_structures.h"

bool is_semicolon(t_nodebt *node)
{
    return (my_strcmp(node->value, ";") == 0);
}