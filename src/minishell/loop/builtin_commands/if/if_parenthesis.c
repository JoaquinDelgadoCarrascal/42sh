/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to manage the if parenthesis
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "stdlib.h"
#include <string.h>

int check_bad_format_string(char *str)
{
    int i = 0;
    int c = 0;

    while (str[i]) {
        if (str[i] == '=' || str[i] == '!')
            c++;
        i++;
    }
    if (c > 0 && str[i - 1] != '=')
        return (print_if_error("if: Badly formed number.\n"));
    i = 0;
    while (str[i]) {
        if ((str[i] == '=' || str[i] == '!') && i > 0 && (str[i - 1] != '!'
        && str[i - 1] != '='))
            return (print_if_error("if: Badly formed number.\n"));
        i++;
    }
    return (SUCCESSFUL);
}

int check_bad_format(char **command, int amount)
{
    int i = 0;

    while (command[i]) {
        if (check_bad_format_string(command[i]) == ERROR)
            return (ERROR);
        i++;
    }
    return (SUCCESSFUL);
}

int check_parenthesis(char **command, int amount)
{
    int pa = find_parenthesis(command, "(");
    int pb = find_parenthesis(command, ")");
    char c = (amount > 3 + pa + pb) ?
    command[3 + pa][strlen(command[3 + pa]) - 1] : '\0';

    if (check_bad_format(command, amount) == ERROR)
        return (ERROR);
    if (pa == 0 && command[1 + pa][0] != '(' && (pb > 0 || c == ')'))
        return (print_if_error("Too many )'s.\n"));
    if (amount < 3 + pa + pb && (pa > 0 || command[1 + pa][0] == '('))
        return (print_if_error("Too many ('s.\n"));
    if (amount < 4 + pa + pb)
        return (print_if_error("if: Expression Syntax.\n"));
    if (pb == 0 && c != ')' && (pa > 0 || command[1 + pa][0] == '('))
        return (print_if_error("Too many ('s.\n"));
    return (SUCCESSFUL);
}

int find_parenthesis(char **command, char *par)
{
    int c = 0;
    int i = 0;

    while (command[i]) {
        if (my_strcmp(command[i], par) == 0)
            c++;
        i++;
    }
    return (c);
}

char **remove_parenthesis(char **command)
{
    int i = 0;
    int size = 0;

    while (command[i]) {
        if (command[i][0] == '(' && my_strcmp(command[i], "(") != 0) {
            command[i] = move_left(command[i], 0);
            break;
        } else if (my_strcmp(command[i], "(") == 0)
            break;
        i++;
    }
    while (command[i]) {
        size = strlen(command[i]) - 1;
        if (command[i][size] == ')' && my_strcmp(command[i], ")") != 0) {
            command[i][size] = '\0';
            break;
        } else if (my_strcmp(command[i], ")") == 0)
            break;
        i++;
    }
    return (command);
}