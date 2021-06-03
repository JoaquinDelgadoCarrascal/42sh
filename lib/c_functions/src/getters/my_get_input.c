/*
** EPITECH PROJECT, 2021
** my_get_input.c
** File description:
** my_get_input.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "c_functions.h"

char *my_get_input(void)
{
    size_t size = 0;
    char *input = NULL;
    char *input_return = NULL;

    if (getline(&input, &size, stdin) == -1) {
        free(input);
        return (NULL);
    }
    input_return = my_cut(input, 0, my_strlen(input) - 2);
    free(input);
    return (input_return);
}