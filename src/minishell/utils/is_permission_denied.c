/*
** EPITECH PROJECT, 2021
** is_permission_denied.c
** File description:
** is_permission_denied.c
*/

#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include "mysh_macros.h"

bool is_permission_denied(char *command)
{
    access(command, F_OK | R_OK | W_OK | X_OK);
    return (errno == NUM_ERROR_PERMISSION_DENIED);
}