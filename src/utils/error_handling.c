/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** error_handling.c
*/

#include "mysh.h"
#include "mysh_macros.h"

int error_handling(int argc)
{
    if (argc != 1)
        return (print_error(ERROR_MESSAGE));
    return (SUCCESSFUL);
}