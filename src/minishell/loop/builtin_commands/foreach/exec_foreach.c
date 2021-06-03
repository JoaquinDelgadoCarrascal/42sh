/*
** EPITECH PROJECT, 2021
** exec_foreach.c
** File description:
** exec_foreach.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include <stdlib.h>
#include <string.h>

t_foreach *add_foreach_command(char *command, t_foreach *prev)
{
    t_foreach *foreach_l = malloc(sizeof(t_foreach));

    foreach_l->command = my_strdup(command);
    foreach_l->previous = prev;
    foreach_l->next = NULL;
    return (foreach_l);
}

int foreach_loop(t_foreach *foreach_l)
{
    char *input = NULL;

    foreach_l->previous = NULL;
    foreach_l->command = my_strdup("start");
    foreach_l->next = NULL;
    while (1) {
        printf(FOREACH_PROMPT);
        input = my_get_input();
        if (input == NULL) {
            printf(FOREACH_NO_END);
            return (ERROR);
        }
        foreach_l->next = add_foreach_command(input, foreach_l);
        if (my_strcmp(input, "end") == 0)
            break;
        free(input);
        foreach_l = foreach_l->next;
    }
    free(input);
    return (2);
}

void execute_foreach_function(char *key, char *argument,
t_minishell *mysh, t_foreach *foreach_l)
{
    char *command = NULL;

    if (my_strcmp(argument, "(") == 0 || my_strcmp(argument, ")") == 0)
        return;
    foreach_l = foreach_l->next;
    while (my_strcmp(foreach_l->command, "end") != 0) {
        command = my_strdup(foreach_l->command);
        command = substitute_key(command, argument, key);
        mysh->bintree = get_tree(mysh, command);
        tree_execution(mysh);
        free_bintree(mysh->bintree);
        foreach_l = foreach_l->next;
    }
}

int exec_foreach(char **command, t_minishell *minishell)
{
    t_foreach *foreach_l = NULL;
    char **env = NULL;
    t_minishell *mysh = NULL;
    int i = 2;

    if (check_foreach(command) == false)
        return (SUCCESSFUL);
    foreach_l = malloc(sizeof(t_foreach));
    env = get_env(minishell->env);
    mysh = minishell_setup(env);
    i = foreach_loop(foreach_l);
    command = transform_arguments(command);
    if (i == 2)
        while (command[i++] != NULL)
            execute_foreach_function(command[1], command[i - 1],
            mysh, foreach_l);
    my_free_array_string(env);
    free_foreach(foreach_l);
    free_minishell(mysh);
    return (SUCCESSFUL);
}