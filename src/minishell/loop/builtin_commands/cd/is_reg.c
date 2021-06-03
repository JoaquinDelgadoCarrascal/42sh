/*
** EPITECH PROJECT, 2021
** is_reg.c
** File description:
** is_reg.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

bool is_reg(char *path)
{
    struct stat path_stat;
    int ret = 0;

    ret = stat(path, &path_stat);
    if (ret == -1)
        return (false);
    return (S_ISREG(path_stat.st_mode));
}