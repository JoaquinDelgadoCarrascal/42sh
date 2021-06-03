/*
** EPITECH PROJECT, 2021
** print_list.c
** File description:
** print_list.c
*/

#include <stddef.h>
#include "c_functions.h"
#include "c_functions_structures.h"

void print_list(t_list *list)
{
    t_nodell *head = NULL;

    if (list != NULL) {
        head = list->head;
        while (list->head != NULL) {
            my_putstr("var_name:");
            if (list->head->info->var_name)
                my_putstr(list->head->info->var_name);
            my_putstr("\n");
            my_putstr("var_value:");
            if (list->head->info->var_name)
                my_putstr(list->head->info->var_value);
            my_putchar('\n');
            list->head = list->head->next;
        }
        list->head = head;
    }
}