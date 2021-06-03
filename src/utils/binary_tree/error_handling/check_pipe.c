/*
** EPITECH PROJECT, 2021
** check_pipe.c
** File description:
** check_pipe.c
*/

#include "c_functions.h"
#include "c_functions_structures.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int check_pipe(t_nodebt *node)
{
    if (my_strcmp(node->left->value, "") == 0 ||
    my_strcmp(node->right->value, "") == 0) {
        my_putstr(NULL_REDIRECTION);
        return (ERROR);
    }
    return (SUCCESSFUL);
}

int error_handling_pipe(t_nodebt *node, t_minishell *minishell)
{
    if (check_pipe(node) == ERROR)
        return (ERROR);
    if (my_strcmp(node->right->value, "|") == 0)
        return (error_handling_pipe(node->right, minishell));
    return (SUCCESSFUL);
}