/*
** EPITECH PROJECT, 2021
** get_value_in_index.c
** File description:
** get_value_in_index.c
*/

#include "c_functions.h"

char *get_value_in_index(t_list *env, int index)
{
    t_nodell *head = NULL;
    int i = 0;
    char *value = NULL;

    if (index < 0 || index > env->size)
        return (NULL);
    head = env->head;
    while (env->head != NULL) {
        if (i == index) {
            value = my_strdup(env->head->info->var_value);
            env->head = head;
            return (value);
        }
        env->head = env->head->next;
        i++;
    }
    env->head = head;
    return (NULL);
}