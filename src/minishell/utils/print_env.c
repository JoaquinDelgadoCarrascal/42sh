/*
** EPITECH PROJECT, 2021
** B-PSU_NO_GIT
** File description:
** print_env.c
*/

#include "c_functions.h"
#include "c_functions_structures.h"
#include "mysh_macros.h"

void print_env(t_list *env)
{
    t_nodell *head = NULL;

    if (env != NULL) {
        head = env->head;
        while (env->head != NULL) {
            my_putstr(env->head->info->var_name);
            my_putchar(DEL_ENV);
            if (env->head->info->var_value)
                my_putstr(env->head->info->var_value);
            my_putchar('\n');
            env->head = env->head->next;
        }
        env->head = head;
    }
}