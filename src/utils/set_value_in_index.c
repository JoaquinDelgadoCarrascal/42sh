/*
** EPITECH PROJECT, 2021
** set_value_in_index.c
** File description:
** set_value_in_index.c
*/

#include <stdlib.h>
#include "c_functions.h"

char *set_value_in_index(t_list *env, int index, char *new_value)
{
    t_nodell *head = NULL;
    int i = 0;
    bool break_loop = true;

    if (index < 0 || index > env->size)
        return (NULL);
    head = env->head;
    while (env->head != NULL && break_loop) {
        if (i == index) {
            free(env->head->info->var_value);
            env->head->info->var_value = my_strdup(new_value);
            break_loop = !break_loop;
        }
        env->head = env->head->next;
        i++;
    }
    env->head = head;
    return (NULL);
}