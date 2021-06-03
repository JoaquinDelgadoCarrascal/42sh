/*
** EPITECH PROJECT, 2021
** print_where.c
** File description:
** print_where.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"

char **get_command_where(char *command)
{
    char **command_argv = malloc(4 * sizeof(char *));

    command_argv[0] = my_strdup("which");
    command_argv[1] = my_strdup("-a");
    command_argv[2] = my_strdup(command);
    command_argv[3] = NULL;
    return (command_argv);
}

void print_where(char *command, t_minishell *minishell)
{
    char **command_argv = get_command_where(command);
    int return_value = 0;

    return_value = do_execve(command_argv, minishell);
    if (return_value == 1)
        minishell->return_value = return_value;
    my_free_array_string(command_argv);
}