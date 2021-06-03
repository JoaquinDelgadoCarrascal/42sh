/*
** EPITECH PROJECT, 2021
** semicolon.c
** File description:
** semicolon.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_structures.h"

void semicolon(t_nodebt *node, t_minishell *minishell)
{
    if (my_strcmp(node->left->value, "") != 0)
        exec_tree(node->left, minishell);
    if (my_strcmp(node->right->value, "") != 0)
        exec_tree(node->right, minishell);
}