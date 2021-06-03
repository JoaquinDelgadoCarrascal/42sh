/*
** EPITECH PROJECT, 2021
** double_or.c
** File description:
** double_or.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

void double_or(t_nodebt *node, t_minishell *minishell)
{
    if (minishell->return_value == TRUE_RETURN)
        exec_tree(node->left, minishell);
    if (minishell->return_value != TRUE_RETURN)
        exec_tree(node->right, minishell);
}