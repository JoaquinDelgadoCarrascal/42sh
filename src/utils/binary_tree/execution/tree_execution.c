/*
** EPITECH PROJECT, 2021
** tree_execution.c
** File description:
** tree_execution.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

bool is_node_priority(t_nodebt *node, t_priorities **priorities)
{
    for (int i = 0; priorities[i]; i++) {
        if (my_strcmp(node->value, priorities[i]->key) == 0)
            return (true);
    }
    return (false);
}

void command_execution(t_nodebt *node, t_minishell *minishell)
{
    char **command = my_split(node->value, " \t");

    minishell->return_value = exec_command(command, minishell);
    my_free_array_string(command);
}

void exec_priority_node(t_nodebt *node, t_minishell *minishell)
{
    for (int i = 0; minishell->priorities[i]; i++) {
        if (my_strcmp(node->value, minishell->priorities[i]->key) == 0)
            minishell->priorities[i]->function(node, minishell);
    }
}

void exec_tree(t_nodebt *node, t_minishell *minishell)
{
    if (is_node_priority(node, minishell->priorities))
        exec_priority_node(node, minishell);
    else
        command_execution(node, minishell);
}

void tree_execution(t_minishell *minishell)
{
    if (!minishell->bintree)
        minishell->exit = true;
    else {
        if (error_handling_tree(minishell->bintree->root, minishell) != ERROR)
            exec_tree(minishell->bintree->root, minishell);
    }
}