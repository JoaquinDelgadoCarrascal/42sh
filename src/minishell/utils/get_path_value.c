/*
** EPITECH PROJECT, 2021
** get_path_value.c
** File description:
** get_path_value.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_structures.h"

char *get_path_value(t_minishell *minishell)
{
    int index = get_index_of_var(minishell->env, "PATH");

    if (index != -1)
        return (get_value_in_index(minishell->env, index));
    return (my_strdup("/usr/local/sbin:/usr/local/bin:/usr/sbin:\
    /usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"));
}