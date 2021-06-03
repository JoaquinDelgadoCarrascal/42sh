/*
** EPITECH PROJECT, 2021
** print_prompt.c
** File description:
** print_prompt.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

char *get_value_env(t_minishell *minishell, char *value, char *default_value)
{
    int index_user = get_index_of_var(minishell->env, value);

    if (index_user == -1)
        return (my_strdup(default_value));
    else
        return (get_value_in_index(minishell->env, index_user));
}

char *get_pwd(char *cwd)
{
    int index = 0;

    while (my_nindex_of(cwd, '/', index) != -1) {
        index = my_nindex_of(cwd, '/', index) + 1;
    }
    index--;
    return (my_cut(cwd, index, my_strlen(cwd)));
}

void print_values_prompt(char *user, char *pwd, char *session)
{
    if (isatty(STDIN_FILENO) != 0) {
        my_putstr(BHGRN);
        my_putstr(user);
        my_putchar('@');
        my_putstr(session);
        my_putstr(WHT);
        my_putchar(':');
        my_putstr(BHBLU);
        my_putchar('~');
        my_putstr(pwd);
        my_putstr(WHT);
        my_putstr("$ ");
        my_putstr(COLOR_RESET);
    }
}

void print_prompt(t_minishell *minishell)
{
    char cwd[256];
    char *pwd = NULL;
    char *user = get_value_env(minishell, "USER", "user");
    char *session_desktop =
    get_value_env(minishell, "XDG_SESSION_DESKTOP", "unknown");

    getcwd(cwd, sizeof(cwd));
    pwd = get_pwd(cwd);
    print_values_prompt(user, pwd, session_desktop);
    free(pwd);
    free(user);
    free(session_desktop);
}