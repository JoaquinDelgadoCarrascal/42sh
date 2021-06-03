/*
** EPITECH PROJECT, 2021
** get_env.c
** File description:
** get_env.c
*/

#include <stdlib.h>
#include "c_functions.h"

char **get_env(t_list *env)
{
    int size = get_list_size(env);
    char **arr_env = malloc((size + 1) * sizeof(char *));
    char *tmp = NULL;
    t_nodell *head = env->head;

    for (int i = 0; i < get_list_size(env); i++) {
        tmp = my_strdup(env->head->info->var_name);
        tmp = my_strcat(tmp, "=");
        tmp = my_strcat(tmp, env->head->info->var_value);
        arr_env[i] = my_strdup(tmp);
        free(tmp);
        env->head = env->head->next;
    }
    env->head = head;
    arr_env[size] = NULL;
    return (arr_env);
}