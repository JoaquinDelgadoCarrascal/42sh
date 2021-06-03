/*
** EPITECH PROJECT, 2021
** my_clean_str.c
** File description:
** my_clean_str.c
*/

#include "c_functions.h"
#include <stdlib.h>

int index_first_letter(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ')
            return (i);
    }
    return (-1);
}

char *my_clean_str(char *str)
{
    int index_first = index_first_letter(str);
    int index_last = 0;
    char *new_str = NULL;

    my_revstr(str);
    index_last = index_first_letter(str);
    my_revstr(str);
    if (index_first == -1 || index_last == -1)
        new_str = my_strdup("");
    else
        new_str = my_cut(str, index_first, my_strlen(str) - index_last - 1);
    free(str);
    return (new_str);
}