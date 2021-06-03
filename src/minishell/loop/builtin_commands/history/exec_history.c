/*
** EPITECH PROJECT, 2021
** exec_history.c
** File description:
** exec_history.c
*/

#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

void print_history(t_list *history)
{
    t_nodell *head = NULL;

    if (history != NULL) {
        head = history->head;
        while (history->head != NULL) {
            my_putstr(history->head->info->var_name);
            my_putchar('\n');
            history->head = history->head->next;
        }
        history->head = head;
    }
}

int exec_history(char **command, t_minishell *minishell)
{
    print_history(minishell->history);
    return (SUCCESSFUL);
}