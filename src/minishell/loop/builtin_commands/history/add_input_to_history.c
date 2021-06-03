/*
** EPITECH PROJECT, 2021
** add_input_to_history.c
** File description:
** add_input_to_history.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"

char *get_num_history(t_minishell *minishell)
{
    char *num = NULL;
    int entry = minishell->history->size + 1;
    int len_entry = my_int_len(entry);
    char *entry_str = my_itoa(entry);
    int num_spaces = 6 - len_entry;
    int i = 0;

    num = malloc((num_spaces + len_entry + 1) * sizeof(char));
    while (i < num_spaces) {
        num[i] = ' ';
        i++;
    }
    while (i - num_spaces < len_entry) {
        num[i] = entry_str[i - num_spaces];
        i++;
    }
    num[i] = '\0';
    free(entry_str);
    return (num);
}

char *get_formated_input(t_minishell *minishell, char *input)
{
    char *num = get_num_history(minishell);
    char *hour = get_hour();
    int total_len = my_strlen(num) + my_strlen(hour) + my_strlen(input) + 3;
    char *formated_input = NULL;

    formated_input = my_strcat(formated_input, num);
    formated_input = my_strcat(formated_input, "\t");
    formated_input = my_strcat(formated_input, hour);
    formated_input = my_strcat(formated_input, "\t");
    formated_input = my_strcat(formated_input, input);
    free(num);
    free(hour);
    return (formated_input);
}

void add_input_to_history(t_minishell *minishell, char *input)
{
    char *formated_input = NULL;
    t_info_node *info = NULL;
    t_nodell *node = NULL;

    if (input) {
        formated_input = get_formated_input(minishell, input);
        info = constructor_info_node(formated_input, NULL);
        node = constructor_node(info);
        minishell->history = add_end(minishell->history, node);
    }
}