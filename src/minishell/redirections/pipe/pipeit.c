/*
** EPITECH PROJECT, 2021
** pipeit.c
** File description:
** pipeit.c
*/

#include <unistd.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"
#include <string.h>
#include <errno.h>

FILE *do_pipe(FILE *tmp_in, t_nodebt *node, t_minishell *minishell)
{
    int fd_stdin = dup(STDIN_FILENO);
    int fd_stdout = dup(STDOUT_FILENO);
    int fd_tmp_in = fileno(tmp_in);
    FILE *tmp_out = tmpfile();
    int fd_tmp_out = fileno(tmp_out);

    dup2(fd_tmp_in, STDIN_FILENO);
    dup2(fd_tmp_out, STDOUT_FILENO);
    command_execution(node, minishell);
    fclose(tmp_in);
    dup2(fd_stdin, STDIN_FILENO);
    close(fd_stdin);
    dup2(fd_stdout, STDOUT_FILENO);
    close(fd_stdout);
    rewind(tmp_out);
    return (tmp_out);
}

FILE *get_first_tmp(t_nodebt *node, t_minishell *minishell)
{
    FILE *tmp = tmpfile();
    int fd_stdout = dup(STDOUT_FILENO);
    int fd_tmp = fileno(tmp);

    dup2(fd_tmp, STDOUT_FILENO);
    exec_tree(node->left, minishell);
    dup2(fd_stdout, STDOUT_FILENO);
    close(fd_stdout);
    rewind(tmp);
    return (tmp);
}

FILE *pipeit(FILE *tmp_in, t_nodebt *node, t_minishell *minishell)
{
    FILE *tmp = NULL;
    char ch;

    if (!tmp_in) {
        tmp = pipeit(get_first_tmp(node, minishell), node->right, minishell);
        print_content_file(tmp);
        fclose(tmp);
        return (NULL);
    }
    if (tmp_in && my_strcmp(node->value, "|") == 0) {
        return (pipeit(do_pipe(tmp_in, node->left, minishell), node->right,
        minishell));
    }
    if (tmp_in && my_strcmp(node->value, "|") != 0)
        return (do_pipe(tmp_in, node, minishell));
    return (NULL);
}

void pipeit_exec(t_nodebt *node, t_minishell *minishell)
{
    pipeit(NULL, node, minishell);
}