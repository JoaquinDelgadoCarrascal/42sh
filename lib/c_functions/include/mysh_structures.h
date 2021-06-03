/*
** EPITECH PROJECT, 2021
** mysh_structures.h
** File description:
** mysh_structures.h
*/

#ifndef MYSH_STRUCTURES_
#define MYSH_STRUCTURES_

#include <stdbool.h>
#include "c_functions_structures.h"

typedef struct s_minishell t_minishell;

typedef struct s_builtin
{
    char *command;
    int (*ptr)(char **command, t_minishell *minishell);
} t_builtin;

typedef struct s_priorities
{
    int priority;
    char *key;
    void (*function)(t_nodebt *node, t_minishell *minishell);
} t_priorities;

struct s_minishell
{
    t_list *env;
    t_list *history;
    t_list *alias;
    t_builtin **builtin;
    t_priorities **priorities;
    t_binarytree *bintree;
    int return_value;
    bool exit;
    int original_fd[2];
};

#endif /* !MYSH_STRUCTURES_ */