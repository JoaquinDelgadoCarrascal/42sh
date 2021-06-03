/*
** EPITECH PROJECT, 2021
** double_out_redirection.c
** File description:
** double_out_redirection.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

void double_out_redirection(t_nodebt *node, t_minishell *minishell)
{
    int fd_stdout = -1;
    int fd_file = -1;

    if (error_handling_output_redirection(node->right->value) != ERROR) {
        fd_stdout = dup(STDOUT_FILENO);
        fd_file = open(node->right->value, O_WRONLY | O_CREAT | O_APPEND, 0664);
        dup2(fd_file, STDOUT_FILENO);
        close(fd_file);
        exec_tree(node->left, minishell);
        dup2(fd_stdout, STDOUT_FILENO);
        close(fd_stdout);
    }
}