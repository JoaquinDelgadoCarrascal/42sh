/*
** EPITECH PROJECT, 2021
** mysh.c
** File description:
** mysh.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int minishell_loop(t_minishell *minishell)
{
    char *input = NULL;
    int ret_value = 0;

    do {
        print_prompt(minishell);
        input = get_input_inhib();
        add_input_to_history(minishell, input);
        minishell->bintree = get_tree(minishell, input);
        tree_execution(minishell);
        free_bintree(minishell->bintree);
    } while (!minishell->exit);
    print_exit();
    ret_value = minishell->return_value;
    free_minishell(minishell);
    return (ret_value);
}

int mysh(char **env)
{
    t_minishell *minishell = minishell_setup(env);

    return (minishell_loop(minishell));
}