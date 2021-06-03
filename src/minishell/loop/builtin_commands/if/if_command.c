/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to get the command from the if
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "stdlib.h"

char *get_if_command(char **command, int size)
{
    int par = find_parenthesis(command, "(") + find_parenthesis(command, ")");
    char *args = my_strdup(command[4 + par]);
    int i = 0;

    while (i < size - (5 + par)) {
        args = my_strcat(args, " ");
        args = my_strcat(args, command[i + 5 + par]);
        i++;
    }
    return (args);
}