/*
** EPITECH PROJECT, 2021
** is_dir.c
** File description:
** is_dir.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

bool is_dir(const char *path)
{
    struct stat path_stat;
    int ret = 0;

    ret = stat(path, &path_stat);
    if (ret == -1)
        return (false);
    return (S_ISDIR(path_stat.st_mode));
}