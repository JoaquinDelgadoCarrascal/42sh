/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to substitute the keys with the arguments
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include <string.h>
#include <stdlib.h>

char *make_substitution(char *org, int i, char *arg, char *key)
{
    int lena = strlen(org);
    int lenb = strlen(arg);
    int lenc = strlen(key);
    char *command = malloc(sizeof(char) * lena + lenb);
    int j = 0;
    int m = 0;

    for (j = 0 ; j < i ; j++)
        command[j] = org[j];
    for (m = 0 ; m < lenb ; m++, j++)
        command[j] = arg[m];
    for (m = i + lenc + 1 ; m < lena ; j++, m++)
        command[j] = org[m];
    command[j] = '\0';
    free(org);
    return (command);
}

char *find_key_argument(char *dest, int i, char *argument, char *key)
{
    int size_arg = strlen(argument);
    int k = 0;

    for (int j = i + 1 ; key[k] ; j++, k++) {
        if (dest[j] != key[k])
            return (dest);
    }
    dest = make_substitution(dest, i, argument, key);
    return (dest);
}

char *substitute_key(char *command, char *argument, char *key)
{
    int size_com = strlen(command);
    int size_key = strlen(key);

    for (int i = 0 ; i < size_com - size_key ; i++)
        if (command[i] == '$') {
            command = find_key_argument(command, i, argument, key);
            size_com = strlen(command);
        }
    return (command);
}

char *move_left(char *str, int j)
{
    int i = j;
    int size = strlen(str);

    while (i < size) {
        str[i] = str[i + 1];
        i++;
    }
    return (str);
}

char **transform_arguments(char **args)
{
    int i = 0;
    int len = 0;

    if (my_strcmp(args[2], "(") != 0 && args[2][0] == '(')
        args[2] = move_left(args[2], 0);
    while (args[i] != NULL)
        i++;
    len = strlen(args[i - 1]) - 1;
    if (my_strcmp(args[i - 1], ")") != 0 && args[i - 1][len] == ')')
        args[i - 1][len] = '\0';
    return (args);
}