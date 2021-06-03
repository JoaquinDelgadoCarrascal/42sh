/*
** EPITECH PROJECT, 2021
** minishell_setup.c
** File description:
** minishell_setup.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

t_minishell *minishell_setup(char **env)
{
    t_minishell *minishell = malloc(sizeof(t_minishell));

    minishell->builtin = builtin_setup();
    minishell->env = env_setup(env);
    minishell->priorities = priorities_setup();
    minishell->return_value = 0;
    minishell->exit = false;
    minishell->history = create_list();
    minishell->alias = create_list();
    minishell->original_fd[0] = dup(STDIN_FILENO);
    minishell->original_fd[1] = dup(STDOUT_FILENO);
    minishell->original_builtins = original_builtins_setup();
    return (minishell);
}