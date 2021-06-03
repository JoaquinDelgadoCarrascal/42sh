/*
** EPITECH PROJECT, 2021
** exec_cd.c
** File description:
** exec_cd.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int error_handling_cd_special_cases(char **command, t_minishell *minishell)
{
    if (my_str_arr_length(command) == 1 &&
        get_index_of_var(minishell->env, "HOME") == -1) {
            my_putstr(CD_NO_EXISTS);
            return (ERROR);
        }
    if (my_str_arr_length(command) > 1) {
        if (my_strcmp(command[1], "-") == 0 &&
        get_index_of_var(minishell->env, "OLDPWD") == -1) {
            my_putstr(CD_NO_EXISTS);
            return (ERROR);
        }
        if ((my_strcmp(command[1], "--") == 0 ||
            my_strcmp(command[1], "home") == 0 ||
            my_str_arr_length(command) == 1) &&
            get_index_of_var(minishell->env, "HOME") == -1) {
            my_putstr(CD_NO_EXISTS);
            return (ERROR);
        }
    }
    return (SUCCESSFUL);
}

int error_handling_cd(char **command, t_minishell *minishell)
{
    if (my_str_arr_length(command) > 2) {
        my_putstr(CD_TOO_MANY);
        return (ERROR);
    }
    if (error_handling_cd_special_cases(command, minishell) == ERROR)
        return (ERROR);
    if (!is_special(command) && !is_dir(command[1])) {
        if (is_reg(command[1])) {
            my_putstr(command[1]);
            my_putstr(CD_NO_DIR);
        }
        else {
            my_putstr(command[1]);
            my_putstr(CD_NO_EXISTS);
        }
        return (ERROR);
    }
    return (SUCCESSFUL);
}

char *get_new_path(char **command, t_minishell *minishell)
{
    if (my_str_arr_length(command) == 1)
        return (get_value_in_index(minishell->env,
        get_index_of_var(minishell->env, "HOME")));
    if (my_strcmp(command[1], "home") == 0)
        my_putstr("~\n");
    if (my_strcmp(command[1], "-") == 0)
        return (get_value_in_index(minishell->env,
        get_index_of_var(minishell->env, "OLDPWD")));
    if ((my_strcmp(command[1], "--") == 0 ||
        my_strcmp(command[1], "home") == 0))
        return (get_value_in_index(minishell->env,
        get_index_of_var(minishell->env, "HOME")));
    return (my_strdup(command[1]));
}

void update_old_path(t_minishell *minishell, char *new_path)
{
    t_nodell *node = NULL;
    t_info_node *info_node = NULL;

    if (get_index_of_var(minishell->env, "OLDPWD") == -1) {
        info_node = constructor_info_node(my_strdup("OLDPWD"),
        my_strdup(new_path));
        node = constructor_node(info_node);
        minishell->env = add_end(minishell->env, node);
    }
    else {
        if (new_path == NULL) {
            set_value_in_index(minishell->env,
            get_index_of_var(minishell->env, "OLDPWD"), my_strdup("."));
        }
        else {
            set_value_in_index(minishell->env,
            get_index_of_var(minishell->env, "OLDPWD"), new_path);
        }
    }
}

int exec_cd(char **command, t_minishell *minishell)
{
    char *new_path = NULL;
    char cwd[256];

    if (error_handling_cd(command, minishell) == ERROR)
        return (FALSE_RETURN);
    new_path = get_new_path(command, minishell);
    getcwd(cwd, sizeof(cwd));
    update_old_path(minishell, cwd);
    chdir(new_path);
    free(new_path);
    return (SUCCESSFUL);
}