/*
** EPITECH PROJECT, 2021
** exec_where.c
** File description:
** exec_where.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

bool error_handling_where(char **command)
{
    if (my_str_arr_length(command) == 1) {
        my_putstr(WHERE_TOO_FEW);
        return (ERROR);
    }
    return (SUCCESSFUL);
}

int exec_where(char **command, t_minishell *minishell)
{
    if (error_handling_where(command) == ERROR)
        return (FALSE_RETURN);
    for (int i = 1; command[i]; i++) {
        where_alias(command[i], minishell);
        where_builtin(command[i], minishell);
        print_where(command[i], minishell);
    }
    return (minishell->return_value);
}