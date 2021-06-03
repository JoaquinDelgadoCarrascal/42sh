/*
** EPITECH PROJECT, 2021
** is_alias.c
** File description:
** is_alias.c
*/

#include "mysh.h"

bool is_alias(char **command, t_minishell *minishell)
{
    int index = get_index_of_var(minishell->alias, command[0]);

    return (index != -1);
}