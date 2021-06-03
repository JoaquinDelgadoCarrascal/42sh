/*
** EPITECH PROJECT, 2021
** my_str_isaplhanum.c
** File description:
** my_str_isaplhanum.c
*/

#include "c_functions.h"

bool my_str_isalphanum(char *str)
{
    int i = 0;

    while (str[i]) {
        if (!my_char_isalpha(str[i]) && !my_char_isnum(str[i]))
            return (false);
        i++;
    }
    return (true);
}