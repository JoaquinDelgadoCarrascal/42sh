/*
** EPITECH PROJECT, 2021
** error_handling_double_or.c
** File description:
** error_handling_double_or.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

int error_handling_double_or(t_nodebt *node, t_minishell *minishell)
{
    if (my_strcmp(node->right->value, "") == 0 ||
    my_strcmp(node->left->value, "") == 0 ||
    my_strcmp(node->right->value, "&&") == 0 ||
    my_strcmp(node->left->value, "&&") == 0) {
        my_putstr(NULL_REDIRECTION);
        return (ERROR);
    }
    if (error_handling_tree(node->left, minishell) == 0 &&
    error_handling_tree(node->right, minishell) == 0)
        return (SUCCESSFUL);
}