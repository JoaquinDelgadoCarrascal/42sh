/*
** EPITECH PROJECT, 2021
** my_split.c
** File description:
** my_split.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "c_functions.h"

bool is_char_del(char c, char *del)
{
    int i = 0;

    while (del[i]) {
        if (del[i] == c)
            return (true);
        i++;
    }
    return (false);
}

int buscar_del(char *str, char *del, int start)
{
    int i = start;

    while (str[i]) {
        if (is_char_del(str[i], del))
            return (i);
        i++;
    }
    return (-1);
}

int count_w(char *str, char *del)
{
    int start = 0;
    int end = buscar_del(str, del, start);
    int last_end = 0;
    int i = 0;
    int count = 0;

    if (end == -1)
        last_end = -1;
    while (end != -1) {
        end = buscar_del(str, del, start);
        if (end - start > 0)
            count++;
        start = end + 1;
        if (end != -1)
            last_end = end;
    }
    if (my_strlen(str) - (last_end + 1) > 0)
        count++;
    return (count);
}

char **my_split(char *str, char *del)
{
    int start = 0;
    int end = buscar_del(str, del, start);
    int last_end = 0;
    char **arr = malloc((count_w(str, del) + 1) * sizeof(char *));
    int i = 0;

    arr[count_w(str, del)] = NULL;
    if (end == -1)
        last_end = -1;
    while (end != -1) {
        end = buscar_del(str, del, start);
        if (end - start > 0)
            arr[i++] = my_cut(str, start, end - 1);
        start = end + 1;
        if (end != -1)
            last_end = end;
    }
    if (my_strlen(str) - (last_end + 1) > 0)
        arr[i] = my_cut(str, last_end + 1, my_strlen(str));
    return (arr);
}