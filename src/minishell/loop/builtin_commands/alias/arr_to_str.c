/*
** EPITECH PROJECT, 2021
** arr_to_str.c
** File description:
** arr_to_str.c
*/

#include <stdlib.h>
#include "c_functions.h"

char *arr_to_str(char **array)
{
    int len = 0;
    char *str = NULL;
    int index = 0;

    for (int i = 0; array[i]; i++)
        len += my_strlen(array[i]);
    len += my_str_arr_length(array) - 1;
    str = malloc((len + 1) * sizeof(char));
    for (int i = 0; array[i]; i++) {
        for (int j = 0; array[i][j]; j++)
            str[index++] = array[i][j];
        if (i < my_str_arr_length(array) - 1)
            str[index++] = ' ';
    }
    str[index] = '\0';
    return (str);
}