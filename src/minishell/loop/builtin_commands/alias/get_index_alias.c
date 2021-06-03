/*
** EPITECH PROJECT, 2021
** get_index_alias.c
** File description:
** get_index_alias.c
*/

#include "c_functions.h"
#include "mysh.h"

int get_index_alias(char *alias_name, t_list *alias)
{
    t_nodell *head = NULL;
    int index = 1;

    if (!alias || !alias->head)
        return (1);
    head = alias->head;
    while (alias->head &&
    my_strcmp(alias->head->info->var_name, alias_name) < 0) {
        alias->head = alias->head->next;
        index++;
    }
    alias->head = head;
    return (index);
}