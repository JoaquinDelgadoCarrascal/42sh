/*
** EPITECH PROJECT, 2021
** print_exit.c
** File description:
** print_exit.c
*/

#include <unistd.h>
#include "c_functions.h"

void print_exit(void)
{
    if (isatty(STDIN_FILENO) != 0)
        my_putstr("exit\n");
}