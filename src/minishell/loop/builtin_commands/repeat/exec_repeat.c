/*
** EPITECH PROJECT, 2021
** exec_repeat.c
** File description:
** exec_repeat.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int error_handling_repeat(char **command)
{
    if (my_str_arr_length(command) < 3) {
        my_putstr(REPEAT_TOO_FER);
        return (ERROR);
    }
    if (!my_str_isnum(command[1])) {
        my_putstr(REPEAT_BADLY);
        return (ERROR);
    }
    return (SUCCESSFUL);
}

char **get_repeat_command(char **command)
{
    char **command_exec = malloc((my_str_arr_length(command) - 2 + 1)
    * sizeof(char *));

    for (int i = 0; i < my_str_arr_length(command) - 2; i++) {
        command_exec[i] = my_strdup(command[i + 2]);
    }
    command_exec[my_str_arr_length(command) - 2] = NULL;
    return (command_exec);
}

int exec_repeat(char **command, t_minishell *minishell)
{
    char **command_exec = NULL;

    if (error_handling_repeat(command) == ERROR)
        return (FALSE_RETURN);
    command_exec = get_repeat_command(command);
    for (int i = 0; i < my_atoi(command[1]); i++) {
        minishell->return_value = exec_command(command_exec, minishell);
    }
    my_free_array_string(command_exec);
    return (SUCCESSFUL);
}