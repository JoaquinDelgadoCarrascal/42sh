/*
** EPITECH PROJECT, 2021
** exec_exit.c
** File description:
** exec_exit.c
*/

#include "c_functions.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int error_handling_exit(char **command)
{
    if (my_str_arr_length(command) > 1) {
        if (!my_str_isnum(command[1]) && my_char_isnum(command[1][0])) {
            my_putstr(EXIT_BAD_FORMED);
            return (ERROR);
        }
        if (!my_str_isnum(command[1]) && !my_char_isnum(command[1][0])) {
            my_putstr(EXIT_EX_SYNTAX);
            return (ERROR);
        }
        if (my_str_arr_length(command) > 2) {
            my_putstr(EXIT_EX_SYNTAX);
            return (ERROR);
        }
    }
    return (SUCCESSFUL);
}

int exec_exit(char **command, t_minishell *minishell)
{
    if (error_handling_exit(command) != ERROR) {
        minishell->exit = true;
        if (command[1] != NULL)
            return (my_atoi(command[1]));
        else
            return (0);
    }
    return (FALSE_RETURN);
}