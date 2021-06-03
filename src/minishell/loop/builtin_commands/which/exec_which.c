/*
** EPITECH PROJECT, 2021
** exec_which.c
** File description:
** exec_which.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

bool error_handling_which(char **command)
{
    if (my_str_arr_length(command) == 1) {
        my_putstr(WHICH_TOO_FEW);
        return (ERROR);
    }
    return (SUCCESSFUL);
}

int exec_which(char **command, t_minishell *minishell)
{
    if (error_handling_which(command) == ERROR)
        return (FALSE_RETURN);
    for (int i = 1; command[i]; i++) {
        which_alias(command[i], minishell);
        which_builtin(command[i], minishell);
        print_which(command[i], minishell);
    }
    return (minishell->return_value);
}