/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to free the foreach resources
*/

#include "c_functions.h"
#include <stdlib.h>
#include "mysh.h"
#include "mysh_macros.h"

void free_foreach(t_foreach *foreach)
{
    t_foreach *tmp = NULL;

    while (foreach) {
        free(foreach->command);
        tmp = foreach;
        foreach = foreach->next;
        free(tmp);
    }
}