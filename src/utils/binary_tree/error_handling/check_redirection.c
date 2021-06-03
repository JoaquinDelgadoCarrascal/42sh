/*
** EPITECH PROJECT, 2021
** check_redirection.c
** File description:
** check_redirection.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

bool is_out_redirection(t_nodebt *node, t_minishell *minishell)
{
    for (int i = 3; i < 5; i++) {
        if (my_strcmp(node->value, minishell->priorities[i]->key) == 0)
            return (true);
    }
    return (false);
}

int check_redirection(t_nodebt *node, t_minishell *minishell)
{
    if (my_strcmp(node->right->value, "") == 0) {
        my_putstr(NO_REDIRECTION);
        return (ERROR);
    }
    if (my_strcmp(node->left->value, "") == 0) {
        my_putstr(NULL_REDIRECTION);
        return (ERROR);
    }
    if (my_strcmp(node->right->value, "|") == 0 &&
    my_strcmp(node->right->left->value, "") == 0) {
        my_putstr(NO_REDIRECTION);
        return (ERROR);
    }
    if (my_strcmp(node->right->value, "|") == 0 &&
    is_out_redirection(node->right, minishell)) {
        my_putstr(AMBIGUOUS_REDIRECTION);
        return (ERROR);
    }
    return (SUCCESSFUL);
}