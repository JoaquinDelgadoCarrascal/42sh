/*
** EPITECH PROJECT, 2021
** do_builtin.c
** File description:
** do_builtin.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int do_builtin(char **command, t_minishell *minishell)
{
    for (int i = 0; minishell->builtin[i]; i++) {
        if (my_strcmp(command[0], minishell->builtin[i]->command) == 0)
            return (minishell->builtin[i]->ptr(command, minishell));
    }
    return (SUCCESSFUL);
}