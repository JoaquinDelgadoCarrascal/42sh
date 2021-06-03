/*
** EPITECH PROJECT, 2021
** exec_if.c
** File description:
** exec_if.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "stdlib.h"

char *cut_var_dollar(char *var)
{
    if (var[0] == '$')
        var = move_left(var, 0);
    return (var);
}

void exec_if_command(char *command, t_minishell *minishell)
{
    char **env = get_env(minishell->env);
    t_minishell *mysh = minishell_setup(env);

    mysh->bintree = get_tree(mysh, command);
    tree_execution(mysh);
    free_bintree(mysh->bintree);
    free_minishell(mysh);
    my_free_array_string(env);
}

int exec_true_if(char **command, t_minishell * minishell, int size)
{
    char *args = get_if_command(command, size);
    int pa = find_parenthesis(command, "(");
    int a = get_index_of_var(minishell->env, cut_var_dollar(command[1 + pa]));
    int b = get_index_of_var(minishell->env, cut_var_dollar(command[3 + pa]));
    char *val_a = (a != -1) ? get_value_in_index(minishell->env, a) :
    my_strdup(command[1 + pa]);
    char *val_b = (b != -1) ? get_value_in_index(minishell->env, b) :
    my_strdup(command[3 + pa]);

    // printf("a = %s, b = %s\n", val_a, val_b);
    if (my_strcmp(val_a, val_b) != 0) {
        free(val_a);
        free(val_b);
        free(args);
        return (SUCCESSFUL);
    }
    exec_if_command(args, minishell);
    free(val_a);
    free(val_b);
    return (SUCCESSFUL);
}

int exec_false_if(char **command, t_minishell * minishell, int size)
{
    char *args = get_if_command(command, size);
    int pa = find_parenthesis(command, "(");
    int a = get_index_of_var(minishell->env, cut_var_dollar(command[1 + pa]));
    int b = get_index_of_var(minishell->env, cut_var_dollar(command[3 + pa]));
    char *val_a = (a != -1) ? get_value_in_index(minishell->env, a) :
    my_strdup(command[1 + pa]);
    char *val_b = (b != -1) ? get_value_in_index(minishell->env, b) :
    my_strdup(command[3 + pa]);

    if (my_strcmp(val_a, val_b) == 0) {
        free(val_a);
        free(val_b);
        free(args);
        return (SUCCESSFUL);
    }
    exec_if_command(args, minishell);
    free(val_a);
    free(val_b);
    return (SUCCESSFUL);
}

int exec_if(char **command, t_minishell *minishell)
{
    int result = SUCCESSFUL;
    int size = count_args(command);
    int pa = find_parenthesis(command, "(");

    if (check_if_errors(command, minishell) == ERROR)
        return (SUCCESSFUL);
    command = remove_parenthesis(command);
    if (my_strcmp(command[2 + pa], "==") == 0)
        result = exec_true_if(command, minishell, size);
    else if (my_strcmp(command[2 + pa], "!=") == 0)
        result = exec_false_if(command, minishell, size);
    return (result);
}