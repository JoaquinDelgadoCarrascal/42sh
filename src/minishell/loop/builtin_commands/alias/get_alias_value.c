/*
** EPITECH PROJECT, 2021
** get_alias_value.c
** File description:
** get_alias_value.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"

char *get_alias_value(char **command)
{
    int len = my_str_arr_length(command) - 2;
    char **alias_value = malloc((len + 1) * sizeof(char *));
    char *str = NULL;

    for (int i = 2; i < my_str_arr_length(command); i++)
        alias_value[i - 2] = my_strdup(command[i]);
    alias_value[len] = NULL;
    str = arr_to_str(alias_value);
    my_free_array_string(alias_value);
    return (str);
}