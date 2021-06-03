/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to check if if operators have errors
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "stdlib.h"

int check_allowed_operators(char *operator)
{
    if (my_strcmp(operator, "==") != 0 && my_strcmp(operator, "!=") != 0) {
        printf("if: Expression Syntax.\n");
        return (ERROR);
    }
    return (SUCCESSFUL);
}

int check_if_operators(char *operator, bool a, bool b)
{
    if (check_allowed_operators(operator) == ERROR)
        return (ERROR);
    return (SUCCESSFUL);
}