/*
** EPITECH PROJECT, 2021
** add_to_alias.c
** File description:
** add_to_alias.c
*/

#include "c_functions.h"
#include "mysh.h"

void add_to_alias(char **command, t_minishell *minishell)
{
    char *alias_name = my_strdup(command[1]);
    char *alias_value = get_alias_value(command);
    t_info_node *info_node = constructor_info_node(alias_name, alias_value);
    t_nodell *node = constructor_node(info_node);
    int index = get_index_alias(alias_name, minishell->alias);

    minishell->alias = add_index(minishell->alias, node, index);
}