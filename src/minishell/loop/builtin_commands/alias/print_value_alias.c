/*
** EPITECH PROJECT, 2021
** print_value_alias.c
** File description:
** print_value_alias.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"

void print_value_alias(char *alias_name, t_list *alias)
{
    int index = get_index_of_var(alias, alias_name);
    char *alias_value = NULL;

    if (index != -1) {
        alias_value = get_value_in_index(alias, index);
        my_putstr(alias_value);
        my_putchar('\n');
        free(alias_value);
    }
}