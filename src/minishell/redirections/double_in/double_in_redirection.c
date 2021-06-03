/*
** EPITECH PROJECT, 2021
** double_in_redirection.c
** File description:
** double_in_redirection.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

void print_prompt_double_in(t_minishell *minishell)
{
    int fd_stdout = dup(STDOUT_FILENO);

    dup2(minishell->original_fd[1], STDOUT_FILENO);
    if (isatty(STDIN_FILENO) != 0)
        my_putstr(CHAR_DOUBLE_IN);
    dup2(fd_stdout, STDOUT_FILENO);
    close(fd_stdout);
}

FILE *get_file_as_input(t_nodebt *node, t_minishell *minishell)
{
    FILE *tmp = tmpfile();
    char *input = NULL;

    do {
        if (input) {
            fprintf(tmp, "%s\n", input);
            free(input);
        }
        print_prompt_double_in(minishell);
        input = my_get_input();
    } while (input && my_strcmp(input, get_value_in_redirection(node)) != 0);
    if (input)
        free(input);
    rewind(tmp);
    return (tmp);
}

void double_in_redirection(t_nodebt *node, t_minishell *minishell)
{
    FILE *tmp = get_file_as_input(node, minishell);
    FILE *tmp_stdout = tmpfile();
    int fd_tmp = fileno(tmp);
    int fd_tmp_stdout = fileno(tmp_stdout);
    int fd_stdin = dup(STDIN_FILENO);
    int fd_stdout = dup(STDOUT_FILENO);

    dup2(fd_tmp, STDIN_FILENO);
    dup2(fd_tmp_stdout, STDOUT_FILENO);
    exec_tree(node->left, minishell);
    fclose(tmp);
    dup2(fd_stdin, STDIN_FILENO);
    close(fd_stdin);
    rewind(tmp_stdout);
    if (my_strcmp(node->right->value, "|") == 0)
        tmp_stdout = pipeit(tmp_stdout, node->right->right, minishell);
    dup2(fd_stdout, STDOUT_FILENO);
    close(fd_stdout);
    print_content_file(tmp_stdout);
    fclose(tmp_stdout);
}