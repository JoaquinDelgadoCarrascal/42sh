/*
** EPITECH PROJECT, 2021
** where_builtin.c
** File description:
** where_builtin.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

void where_builtin(char *command, t_minishell *minishell)
{
    if (my_mindex_of(minishell->original_builtins, command) != -1) {
        my_putstr(command);
        my_putstr(WHERE_BUILTIN);
    }
}