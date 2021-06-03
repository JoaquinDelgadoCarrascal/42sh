/*
** EPITECH PROJECT, 2021
** free_minishell.c
** File description:
** free_minishell.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "c_functions.h"
#include "mysh_structures.h"

void free_array_priorities(t_priorities **array)
{
    for (int i = 0; array[i]; i++) {
        free(array[i]->key);
        free(array[i]);
    }
    free(array);
}

void free_builtins(t_builtin **builtins)
{
    for (int i = 0; builtins[i]; i++) {
        free(builtins[i]->command);
        free(builtins[i]);
    }
    free(builtins);
}

void free_minishell(t_minishell *minishell)
{
    free_list(minishell->env);
    free_list(minishell->history);
    free_list(minishell->alias);
    free_builtins(minishell->builtin);
    free_array_priorities(minishell->priorities);
    my_free_array_string(minishell->original_builtins);
    close(minishell->original_fd[0]);
    close(minishell->original_fd[1]);
    free(minishell);
}