/*
** EPITECH PROJECT, 2021
** get_path_bin.c
** File description:
** get_path_bin.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

char *get_path_bin(char *command, t_minishell *minishell)
{
    char *value_path = get_path_value(minishell);
    char **array_path = my_split(value_path, DEL_ATRIB);
    char *path_test = NULL;

    free(value_path);
    for (int i = 0; array_path[i]; i++) {
        path_test = malloc((my_strlen(array_path[i]) + 1) * sizeof(char));
        if (!path_test)
            return (NULL);
        my_strcpy(path_test, array_path[i]);
        path_test = my_strcat(path_test, "/");
        path_test = my_strcat(path_test, command);
        if (access(path_test, F_OK) == 0) {
            my_free_array_string(array_path);
            return (path_test);
        }
        free(path_test);
    }
    my_free_array_string(array_path);
    return (NULL);
}