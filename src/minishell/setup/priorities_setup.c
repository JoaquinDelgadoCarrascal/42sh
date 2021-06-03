/*
** EPITECH PROJECT, 2021
** priorities_setup.c
** File description:
** priorities_setup.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

t_priorities *setup_priority(int priority, char *key,
void function(t_nodebt *, t_minishell *))
{
    t_priorities *dict = malloc(sizeof(t_priorities));

    dict->priority = priority;
    dict->key = my_strdup(key);
    dict->function = function;
    return (dict);
}

t_priorities **priorities_setup(void)
{
    t_priorities **array = malloc(9 * sizeof(t_priorities *));

    array[0] = setup_priority(1, ";", *semicolon);
    array[1] = setup_priority(2, "&&", *double_and);
    array[2] = setup_priority(2, "||", *double_or);
    array[3] = setup_priority(3, ">", *simple_out_redirection);
    array[4] = setup_priority(3, ">>", *double_out_redirection);
    array[5] = setup_priority(4, "<", *simple_in_redirection);
    array[6] = setup_priority(4, "<<", *double_in_redirection);
    array[7] = setup_priority(5, "|", *pipeit_exec);
    array[8] = NULL;
    return (array);
}