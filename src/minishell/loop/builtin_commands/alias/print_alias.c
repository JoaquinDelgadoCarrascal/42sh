/*
** EPITECH PROJECT, 2021
** print_alias.c
** File description:
** print_alias.c
*/

#include "c_functions.h"

void print_bracket(char *var_value, char bracket)
{
    if (my_index_of(var_value, ' ') != -1)
        my_putchar(bracket);
}

void print_alias(t_list *alias)
{
    t_nodell *head = NULL;

    if (alias != NULL) {
        head = alias->head;
        while (alias->head != NULL) {
            my_putstr(alias->head->info->var_name);
            my_putchar('\t');
            print_bracket(alias->head->info->var_value, '(');
            my_putstr(alias->head->info->var_value);
            print_bracket(alias->head->info->var_value, ')');
            my_putchar('\n');
            alias->head = alias->head->next;
        }
        alias->head = head;
    }
}