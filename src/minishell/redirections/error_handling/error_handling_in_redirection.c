/*
** EPITECH PROJECT, 2021
** error_handling_in_redirection.c
** File description:
** error_handling_in_redirection.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

int error_handling_in_redirection(char *path)
{
    if (my_strlen(path) > 255) {
        my_putstr(path);
        my_putstr(TOO_LONG_NAME);
        return (ERROR);
    }
    if ((is_dir(path) || !is_reg(path)) && my_strcmp(path, "|") != 0) {
        my_putstr(path);
        my_putstr(FILE_NO_EXIST);
        return (ERROR);
    }
    return (SUCCESSFUL);
}