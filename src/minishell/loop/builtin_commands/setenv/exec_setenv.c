/*
** EPITECH PROJECT, 2021
** exec_setenv.c
** File description:
** exec_setenv.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int error_handling_setenv(char **command, t_minishell *minishell)
{
    if (my_str_arr_length(command) > 3)
        return (print_error_setenv(SETENV_TOO_MANY));
    if (my_str_arr_length(command) == 1) {
        print_env(minishell->env);
        return (ERROR);
    }
    if (my_str_arr_length(command) > 1) {
        if (!my_str_isalphanum(command[1]))
            return (print_error_setenv(SETENV_ALPHANUM));
        if (my_char_isnum(command[1][0]))
            return (print_error_setenv(SETENV_START_NUM));
    }
    return (SUCCESSFUL);
}

bool is_env_exists(char **command, t_minishell *minishell)
{
    t_nodell *head = minishell->env->head;

    while (minishell->env->head != NULL) {
        if (my_strcmp(command[1], minishell->env->head->info->var_name) == 0) {
            minishell->env->head = head;
            return (true);
        }
        minishell->env->head = minishell->env->head->next;
    }
    minishell->env->head = head;
    return (false);
}

char *get_new_value(char **command)
{
    if (my_str_arr_length(command) == 2)
        return (my_strdup(""));
    return (my_strdup(command[2]));
}

int add_env(char **command, t_minishell *minishell)
{
    int index = 0;
    char *var_value = NULL;
    t_nodell *node = NULL;
    t_info_node *info_node = NULL;

    if (is_env_exists(command, minishell)) {
        index = get_index_of_var(minishell->env, command[1]);
        var_value = get_new_value(command);
        set_value_in_index(minishell->env, index, var_value);
        free(var_value);
    }
    else {
        info_node = constructor_info_node(my_strdup(command[1]),
        get_new_value(command));
        node = constructor_node(info_node);
        minishell->env = add_end(minishell->env, node);
    }
    return (SUCCESSFUL);
}

int exec_setenv(char **command, t_minishell *minishell)
{
    if (error_handling_setenv(command, minishell) != ERROR) {
        return (add_env(command, minishell));
    }
    return (SUCCESSFUL);
}