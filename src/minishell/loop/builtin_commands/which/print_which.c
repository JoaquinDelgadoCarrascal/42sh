/*
** EPITECH PROJECT, 2021
** print_which.c
** File description:
** print_which.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

char **get_command_which(char *command)
{
    char **command_argv = malloc(sizeof(char *) * 3);

    command_argv[0] = my_strdup("which");
    command_argv[1] = my_strdup(command);
    command_argv[2] = NULL;
    return (command_argv);
}

void print_which(char *command, t_minishell *minishell)
{
    int index = get_index_of_var(minishell->alias, command);
    char **command_argv = NULL;
    int return_value = 0;

    if (index == -1 &&
    my_mindex_of(minishell->original_builtins, command) == -1 &&
    is_existing_command(command, minishell)) {
        command_argv = get_command_which(command);
        return_value = do_execve(command_argv, minishell);
        if (return_value == 1)
            minishell->return_value = return_value;
        my_free_array_string(command_argv);
    }
    else if (index == -1 &&
    my_mindex_of(minishell->original_builtins, command) == -1 &&
    !is_existing_command(command, minishell)) {
        my_putstr(command);
        my_putstr(COMMAND_NOT_FOUND);
        minishell->return_value = FALSE_RETURN;
    }
}