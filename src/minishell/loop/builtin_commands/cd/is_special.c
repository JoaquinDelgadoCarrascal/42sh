/*
** EPITECH PROJECT, 2021
** is_special.c
** File description:
** is_special.c
*/

#include "c_functions.h"

bool is_special(char **command)
{
    if (my_str_arr_length(command) == 1 || my_strcmp(command[1], "-") == 0 ||
    my_strcmp(command[1], "--") == 0 || my_strcmp(command[1], "home") == 0)
        return (true);
    return (false);
}