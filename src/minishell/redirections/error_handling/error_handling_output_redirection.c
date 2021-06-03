/*
** EPITECH PROJECT, 2021
** error_handling_output_redirection.c
** File description:
** error_handling_output_redirection.c
*/

#include "c_functions.h"
#include "c_functions_macros.h"
#include "mysh.h"
#include "mysh_macros.h"

int error_handling_output_redirection(char *path)
{
    if (my_strlen(path) > 255) {
        my_putstr(path);
        my_putstr(TOO_LONG_NAME);
        return (ERROR);
    }
    return (SUCCESSFUL);
}