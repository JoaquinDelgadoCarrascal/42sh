/*
** EPITECH PROJECT, 2021
** get_index_of_var.c
** File description:
** get_index_of_var.c
*/

#include <stddef.h>
#include "c_functions.h"
#include "c_functions_structures.h"

int get_index_of_var(t_list *env, char *var_name)
{
    t_nodell *head = NULL;
    int i = 0;

    if (env == NULL)
        return (-1);
    head = env->head;
    while (env->head != NULL) {
        if (my_strcmp(env->head->info->var_name, var_name) == 0) {
            env->head = head;
            return (i);
        }
        env->head = env->head->next;
        i++;
    }
    env->head = head;
    return (-1);
}