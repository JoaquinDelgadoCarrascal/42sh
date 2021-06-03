/*
** EPITECH PROJECT, 2021
** error_handling_tree.c
** File description:
** error_handling_tree.c
*/

#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int error_handling_tree_node(t_nodebt *node, t_minishell *minishell)
{
    if (is_redirection(node, minishell) || is_semicolon(node))
        return (error_handling_tree(node->left, minishell));
    if (is_pipe(node) || is_double_and(node) || is_double_or(node))
        return (SUCCESSFUL);
}

int error_handling_tree(t_nodebt *node, t_minishell *minishell)
{
    if (is_node_priority(node, minishell->priorities)) {
        if (error_handling_tree_node(node, minishell) == ERROR)
            return (ERROR);
        if (is_redirection(node, minishell))
            return (check_redirection(node, minishell));
        if (is_pipe(node))
            return (error_handling_pipe(node, minishell));
        if (is_double_and(node))
            return (error_handling_double_and(node, minishell));
        if (is_double_or(node))
            return (error_handling_double_or(node, minishell));
        return (error_handling_tree(node->right, minishell));
    }
    else
        return (SUCCESSFUL);
}