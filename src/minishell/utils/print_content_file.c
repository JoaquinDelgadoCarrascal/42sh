/*
** EPITECH PROJECT, 2021
** print_content_file.c
** File description:
** print_content_file.c
*/

#include <stdio.h>
#include "c_functions.h"

void print_content_file(FILE *file)
{
    char c = '\0';

    rewind(file);
    while ((c = fgetc(file)) != EOF)
        my_putchar(c);
}