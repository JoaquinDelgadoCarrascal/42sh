/*
** EPITECH PROJECT, 2021
** simple_in_redirection.c
** File description:
** simple_in_redirection.c
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

FILE *do_simple_in_redirection(t_nodebt *node, t_minishell *minishell)
{
    FILE *tmp = tmpfile();
    int fd_tmp = fileno(tmp);
    int fd_stdin = dup(STDIN_FILENO);
    int fd_file = open(get_value_in_redirection(node), O_RDONLY);
    int fd_stdout = dup(STDOUT_FILENO);

    dup2(fd_tmp, STDOUT_FILENO);
    dup2(fd_file, STDIN_FILENO);
    close(fd_file);
    exec_tree(node->left, minishell);
    dup2(fd_stdin, STDIN_FILENO);
    close(fd_stdin);
    rewind(tmp);
    if (my_strcmp(node->right->value, "|") == 0)
        tmp = pipeit(tmp, node->right->right, minishell);
    dup2(fd_stdout, STDOUT_FILENO);
    close(fd_stdout);
    return (tmp);
}

void simple_in_redirection(t_nodebt *node, t_minishell *minishell)
{
    FILE *tmp = NULL;

    if (error_handling_in_redirection(node->right->value) != ERROR) {
        tmp = do_simple_in_redirection(node, minishell);
        print_content_file(tmp);
        fclose(tmp);
    }
}