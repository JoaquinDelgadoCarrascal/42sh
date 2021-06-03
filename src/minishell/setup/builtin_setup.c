/*
** EPITECH PROJECT, 2021
** builtin_setup.c
** File description:
** builtin_setup.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

t_builtin *builtin_struct_setup(char *command,
int function(char **, t_minishell *))
{
    t_builtin *builtin = malloc(sizeof(t_builtin));

    builtin->command = my_strdup(command);
    builtin->ptr = function;
    return (builtin);
}

t_builtin **builtin_setup(void)
{
    t_builtin **builtin = malloc((NUM_COMMANDS + 1) * sizeof(t_builtin *));

    builtin[0] = builtin_struct_setup(CD, *exec_cd);
    builtin[1] = builtin_struct_setup(SETENV, *exec_setenv);
    builtin[2] = builtin_struct_setup(UNSETENV, *exec_unsetenv);
    builtin[3] = builtin_struct_setup(ENV, *exec_env);
    builtin[4] = builtin_struct_setup(EXIT, *exec_exit);
    builtin[5] = builtin_struct_setup(REPEAT, *exec_repeat);
    builtin[6] = builtin_struct_setup(HISTORY, *exec_history);
    builtin[7] = builtin_struct_setup(ALIAS, *exec_alias);
    builtin[8] = builtin_struct_setup(FOREACH, *exec_foreach);
    builtin[9] = builtin_struct_setup(WHERE, *exec_where);
    builtin[10] = builtin_struct_setup(WHICH, *exec_which);
    builtin[11] = builtin_struct_setup(IF, *exec_if);
    builtin[12] = NULL;
    return (builtin);
}