/*
** EPITECH PROJECT, 2021
** which_alias.c
** File description:
** which_alias.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

void which_alias(char *command, t_minishell *minishell)
{
    int index = get_index_of_var(minishell->alias, command);
    char *value = NULL;

    if (index != -1) {
        value = get_value_in_index(minishell->alias, index);
        my_putstr(command);
        my_putstr(WHICH_ALIAS);
        my_putstr(value);
        my_putchar('\n');
        free(value);
    }
}