/*
** EPITECH PROJECT, 2021
** is_builtin.c
** File description:
** is_builtin.c
*/

#include "c_functions.h"
#include "mysh_structures.h"

bool is_builtin(char **command, t_minishell *minishell)
{
    if (!command)
        return (false);
    for (int i = 0; minishell->builtin[i]; i++) {
        if (my_strcmp(command[0], minishell->builtin[i]->command) == 0) {
            return (true);
        }
    }
    return (false);
}