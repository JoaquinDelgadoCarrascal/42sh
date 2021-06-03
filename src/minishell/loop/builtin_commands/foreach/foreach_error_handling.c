/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to do the error handling for the foreach
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

bool check_foreach(char **command)
{
    if (my_str_arr_length(command) < 3) {
        printf(FOREACH_TOO_FEW);
        return (false);
    }
    if ((command[1][0] < 'a' || command[1][0] > 'z') && (command[1][0] < 'A'
    || command[1][0] > 'Z')) {
        printf(FOREACH_VAR_LETTER);
        return (false);
    }
    return (true);
}