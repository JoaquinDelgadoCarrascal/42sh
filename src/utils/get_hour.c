/*
** EPITECH PROJECT, 2021
** get_hour.c
** File description:
** get_hour.c
*/

#include <stdlib.h>
#include <time.h>
#include "c_functions.h"

char put_str(char *str, int pos)
{
    if (my_strlen(str) == 1 && pos == 0)
        return ('0');
    if (my_strlen(str) == 1 && pos == 1)
        return (str[0]);
    return (str[pos]);
}

char *get_hour(void)
{
    char *hour = malloc(6 * sizeof(char));
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour_num = tm_struct->tm_hour;
    int min_num = tm_struct->tm_min;
    char *hour_str = my_itoa(hour_num);
    char *min_str = my_itoa(min_num);

    hour[0] = put_str(hour_str, 0);
    hour[1] = put_str(hour_str, 1);
    hour[2] = ':';
    hour[3] = put_str(min_str, 0);
    hour[4] = put_str(min_str, 1);
    hour[5] = '\0';
    free(hour_str);
    free(min_str);
    return (hour);
}