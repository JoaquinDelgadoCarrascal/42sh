/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** functions to manage the inhibitors
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"
#include <stdlib.h>
#include <string.h>

char *get_inhibitor_values(char *input)
{
    int size = 0;
    int temp_size = strlen(input);
    char *temp = NULL;

    while (1) {
        printf("? ");
        if (temp = my_get_input(), !temp)
            return (input);
        input = my_strcat(input, " ");
        input = my_strcat(input, temp);
        size = strlen(input);
        temp_size = strlen(temp);
        if (size > 0 && input[size - 1] == '\\')
            input[size - 1] = '\0';
        else
            break;
        free(temp);
    }
    free(temp);
    return (input);
}

char *get_input_inhib(void)
{
    char *input = my_get_input();
    int size = 0;

    if (input) {
        size = strlen(input);
        if (size > 0 && input[size - 1] != '\\')
            return (input);
        else if (size > 0) {
            input[size - 1] = '\0';
            input = get_inhibitor_values(input);
        }
    }
    return (input);
}