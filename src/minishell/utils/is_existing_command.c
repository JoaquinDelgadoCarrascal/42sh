/*
** EPITECH PROJECT, 2021
** is_existing_command.c
** File description:
** is_existing_command.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

bool command_has_backslash(char *command)
{
    return (my_index_of(command, '/') != -1);
}

bool without_path(char *command, t_minishell *minishell)
{
    char *value_path = get_path_value(minishell);
    char **array_path = my_split(value_path, DEL_ATRIB);
    char *path_test = NULL;

    free(value_path);
    for (int i = 0; array_path[i]; i++) {
        path_test = malloc((my_strlen(array_path[i]) + 1) * sizeof(char));
        my_strcpy(path_test, array_path[i]);
        path_test = my_strcat(path_test, "/");
        path_test = my_strcat(path_test, command);
        if (access(path_test, F_OK) == 0) {
            free(path_test);
            my_free_array_string(array_path);
            return (true);
        }
        free(path_test);
    }
    my_free_array_string(array_path);
    return (false);
}

bool with_path(char *command, t_minishell *minishell)
{
    return (access(command, F_OK) == 0 && !is_dir(command));
}

bool is_existing_command(char *command, t_minishell *minishell)
{
    if (without_path(command, minishell) && !command_has_backslash(command))
        return (true);
    if (with_path(command, minishell))
        return (true);
    return (false);
}