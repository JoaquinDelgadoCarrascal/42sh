/*
** EPITECH PROJECT, 2021
** exec_unsetenv.c
** File description:
** exec_unsetenv.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int error_handling_unsetenv(char **command)
{
    if (my_str_arr_length(command) == 1) {
        my_putstr(UNSETENV_TOO_FEW);
        return (ERROR);
    }
    return (SUCCESSFUL);
}

int exec_unsetenv(char **command, t_minishell *minishell)
{
    int index = 0;

    if (error_handling_unsetenv(command) == ERROR)
        return (SUCCESSFUL);
    for (int i = 1; command[i]; i++) {
        index = get_index_of_var(minishell->env, command[i]);
        if (index != -1)
            minishell->env = delete_index(minishell->env, index);
    }
    return (SUCCESSFUL);
}