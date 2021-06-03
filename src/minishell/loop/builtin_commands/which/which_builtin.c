/*
** EPITECH PROJECT, 2021
** which_builtin.c
** File description:
** which_builtin.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

void which_builtin(char *command, t_minishell *minishell)
{
    int index = get_index_of_var(minishell->alias, command);

    if (index == -1 &&
    my_mindex_of(minishell->original_builtins, command) != -1) {
        my_putstr(command);
        my_putstr(WHICH_BUILTIN);
    }
}