/*
** EPITECH PROJECT, 2021
** exec_alias.c
** File description:
** exec_alias.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

int exec_alias(char **command, t_minishell *minishell)
{
    if (my_str_arr_length(command) == 1)
        print_alias(minishell->alias);
    if (my_str_arr_length(command) == 2)
        print_value_alias(command[1], minishell->alias);
    if (my_str_arr_length(command) > 2 &&
    get_index_of_var(minishell->alias, command[1]) == -1)
        add_to_alias(command, minishell);
    else if (my_str_arr_length(command) > 2 &&
    get_index_of_var(minishell->alias, command[1]) != -1)
        change_alias(command, minishell);
    return (SUCCESSFUL);
}