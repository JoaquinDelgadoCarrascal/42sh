/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** function to count the arguments
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

int count_args(char **args)
{
    int i = 0;

    while (args[i] != NULL)
        i++;
    return (i);
}