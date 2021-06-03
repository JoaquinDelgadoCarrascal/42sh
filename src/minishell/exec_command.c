/*
** EPITECH PROJECT, 2021
** exec_command.c
** File description:
** exec_command.c
*/

#include <unistd.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"

int command_not_found(char *command, t_minishell *minishell)
{
    int fd_tmp = dup(STDOUT_FILENO);

    dup2(minishell->original_fd[STDOUT_FILENO], STDOUT_FILENO);
    my_putstr(command);
    if (is_permission_denied(command))
        my_putstr(PERMISSION_DENIED);
    else
        my_putstr(COMMAND_NOT_FOUND);
    dup2(fd_tmp, STDOUT_FILENO);
    close(fd_tmp);
    return (FALSE_RETURN);
}

int exec_command(char **command, t_minishell *minishell)
{
    int fd_tmp = -1;

    if (!command) {
        minishell->exit = true;
        return (0);
    }
    if (!command[0])
        return (0);
    if (is_alias(command, minishell))
        return (do_alias(command, minishell));
    if (is_builtin(command, minishell))
        return (do_builtin(command, minishell));
    else if (is_existing_command(command[0], minishell))
        return (do_execve(command, minishell));
    else
        return (command_not_found(command[0], minishell));
}