/*
** EPITECH PROJECT, 2021
** change_alias.c
** File description:
** change_alias.c
*/

#include <stdlib.h>
#include "mysh.h"
#include "mysh_structures.h"

void change_alias(char **command, t_minishell *minishell)
{
    int index = get_index_of_var(minishell->alias, command[1]);
    char *alias_value = get_alias_value(command);

    set_value_in_index(minishell->alias, index, alias_value);
    free(alias_value);
}