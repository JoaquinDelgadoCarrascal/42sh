/*
** EPITECH PROJECT, 2021
** double_and.c
** File description:
** double_and.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

void double_and(t_nodebt *node, t_minishell *minishell)
{
    exec_tree(node->left, minishell);
    if (minishell->return_value == TRUE_RETURN ||
    my_strcmp(node->right->value, "||") == 0)
        exec_tree(node->right, minishell);
}