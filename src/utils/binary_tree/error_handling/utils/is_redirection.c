/*
** EPITECH PROJECT, 2021
** is_redirection.c
** File description:
** is_redirection.c
*/

#include "c_functions.h"
#include "c_functions_structures.h"
#include "mysh_structures.h"

bool is_redirection(t_nodebt *node, t_minishell *minishell)
{
    for (int i = 3; i < 7; i++) {
        if (my_strcmp(node->value, minishell->priorities[i]->key) == 0)
            return (true);
    }
    return (false);
}