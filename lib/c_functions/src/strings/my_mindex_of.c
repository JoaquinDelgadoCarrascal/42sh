/*
** EPITECH PROJECT, 2021
** my_mindex_of.c
** File description:
** Get index of str inside array str
*/

#include "c_functions.h"

int my_mindex_of(char **matrix, char *str)
{
    int i = 0;

    while (matrix[i]) {
        if (my_strcmp(matrix[i], str) == 0)
            return (i);
        i++;
    }
    return (-1);
}