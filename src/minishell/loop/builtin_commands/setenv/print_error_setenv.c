/*
** EPITECH PROJECT, 2021
** print_error_setenv.c
** File description:
** print_error_setenv.c
*/

#include "c_functions.h"
#include "mysh_macros.h"

int print_error_setenv(char *error_message)
{
    my_putstr(SETENV_CMD);
    my_putstr(error_message);
    return (ERROR);
}