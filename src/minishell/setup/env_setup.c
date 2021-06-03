/*
** EPITECH PROJECT, 2021
** env_setup.c
** File description:
** env_setup.c
*/

#include "c_functions.h"
#include "mysh_macros.h"

t_list *env_setup(char **env)
{
    t_list *env_list = create_list();
    t_nodell *node = NULL;
    t_info_node *info_node = NULL;
    char *var_name = NULL;
    char *var_value = NULL;
    int index_del = 0;

    for (int i = 0; env[i]; i++) {
        index_del = my_index_of(env[i], DEL_ENV);
        if (index_del == -1)
            continue;
        var_name = my_cut(env[i], 0, index_del - 1);
        var_value = my_cut(env[i], index_del + 1, my_strlen(env[i]));
        info_node = constructor_info_node(var_name, var_value);
        node = constructor_node(info_node);
        env_list = add_end(env_list, node);
    }
    return (env_list);
}