/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to check errors within the if
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "stdlib.h"
#include <string.h>

int print_if_error(char *err)
{
    printf("%s", err);
    return (ERROR);
}

int print_variable_error(char *vara, char *varb, int d)
{
    if (d == 0)
        printf("%s: undefined variable.\n", vara);
    if (d == 1)
        printf("%s: undefined variable.\n", varb);
    free(vara);
    free(varb);
    return (ERROR);
}

char *cut_variable(char *var, bool *is_num)
{
    if (my_isnum(var) == 1) {
        (*is_num) = true;
        return (var);
    }
    if (var[0] == '$')
        var = move_left(var, 0);
    return (var);
}

int check_if_variables(char **command, t_minishell *minishell)
{
    bool is_numa = false;
    bool is_numb = false;
    int pa = find_parenthesis(command, "(");
    int pb = find_parenthesis(command, ")");
    char *variablea = my_strdup(command[1 + pa]);
    char *variableb = my_strdup(command[3 + pa]);

    variablea = cut_variable(variablea, &is_numa);
    variableb = cut_variable(variableb, &is_numb);
    if (check_if_operators(command[2 + pa], is_numa, is_numb) == ERROR)
        return (print_variable_error(variablea, variableb, 2));
    if (!is_numa && variablea[0] != '"' && command[1 + pa][0] == '$'
    && get_index_of_var(minishell->env, variablea) == -1)
        return (print_variable_error(variablea, variableb, 0));
    if (!is_numb && variableb[0] != '"' && command[3 + pb][0] == '$'
    && get_index_of_var(minishell->env, variableb) == -1)
        return (print_variable_error(variablea, variableb, 1));
    free(variablea);
    free(variableb);
    return (SUCCESSFUL);
}

int check_if_errors(char **command, t_minishell *minishell)
{
    int amount = count_args(command);
    int par = find_parenthesis(command, "(") + find_parenthesis(command, ")");
    char c = command[amount - 1][strlen(command[amount - 1]) - 1];

    if (amount == 1)
        return (print_if_error("if: Too few arguments.\n"));
    if (check_parenthesis(command, amount) == ERROR)
        return (ERROR);
    if (my_strcmp(command[amount - 1], ")") == 0 || c == ')' || amount <= 4)
        return (print_if_error("if: Empty if.\n"));
    command = remove_parenthesis(command);
    return (check_if_variables(command, minishell));
}
