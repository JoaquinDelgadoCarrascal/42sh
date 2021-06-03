/*
** EPITECH PROJECT, 2021
** exec_env.c
** File description:
** exec_env.c
*/

#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int exec_env(char **command, t_minishell *minishell)
{
    print_env(minishell->env);
    return (SUCCESSFUL);
}