/*
** EPITECH PROJECT, 2021
** get_command.c
** File description:
** get_command.c
*/

#include <stddef.h>
#include "c_functions.h"

char **get_command(char *input)
{
    if (!input)
        return (NULL);
    return (my_split(input, " \t"));
}