/*
** EPITECH PROJECT, 2021
** do_alias.c
** File description:
** do_alias.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

int exec_command_alias(char *name_alias, char **value_alias,
t_minishell *minishell)
{
    int return_value = 0;

    if (my_strcmp(name_alias, value_alias[0]) == 0)
        return_value = do_execve(value_alias, minishell);
    else
        return_value = exec_command(value_alias, minishell);
    return (return_value);
}

char **get_val_array(char *val)
{
    if (val)
        return (my_split(val, " "));
    return (NULL);
}

bool is_alias_loop(char **command, t_list *alias)
{
    int index = get_index_of_var(alias, command[0]);
    char *val = get_value_in_index(alias, index);
    char **val_array = my_split(val, " ");

    do {
        if (index == get_index_of_var(alias, val_array[0]))
            index = -1;
        else
            index = get_index_of_var(alias, val_array[0]);
        free(val);
        my_free_array_string(val_array);
        val = get_value_in_index(alias, index);
        val_array = get_val_array(val);
    } while (index != get_index_of_var(alias, command[0]) && index != -1);
    if (val)
        free(val);
    if (val_array)
        my_free_array_string(val_array);
    return (index != -1);
}

int exec_do_alias(char **command, t_minishell *minishell)
{
    int index = get_index_of_var(minishell->alias, command[0]);
    char *value = get_value_in_index(minishell->alias, index);
    char **command_alias = my_split(value, " ");
    int size = (my_str_arr_length(command_alias) +
    (my_str_arr_length(command) - 1) + 1);
    char **command_merge = malloc(size * sizeof(char *));

    for (int i = 0; command_alias[i]; i++)
        command_merge[i] = my_strdup(command_alias[i]);
    for (int i = 0; command[i + 1]; i++)
        command_merge[my_str_arr_length(command_alias) + i] =
        my_strdup(command[i + 1]);
    command_merge[size - 1] = NULL;
    my_free_array_string(command_alias);
    minishell->return_value = exec_command_alias(command[0], command_merge,
    minishell);
    my_free_array_string(command_merge);
    free(value);
    return (minishell->return_value);
}

int do_alias(char **command, t_minishell *minishell)
{
    if (is_alias_loop(command, minishell->alias)) {
        my_putstr(ALIAS_LOOP);
        return (FALSE_RETURN);
    }
    return (exec_do_alias(command, minishell));
}