/*
** EPITECH PROJECT, 2021
** get_name_in_index.c.c
** File description:
** get_name_in_index.c.c
*/

#include "c_functions.h"

char *get_name_in_index(t_list *env, int index)
{
    t_nodell *head = NULL;
    int i = 0;
    char *name = NULL;

    if (index < 0 || index > env->size)
        return (NULL);
    head = env->head;
    while (env->head != NULL) {
        if (i == index) {
            name = my_strdup(env->head->info->var_name);
            env->head = head;
            return (name);
        }
        env->head = env->head->next;
        i++;
    }
    env->head = head;
    return (NULL);
}