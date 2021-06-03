/*
** EPITECH PROJECT, 2021
** do_execve.c
** File description:
** do_execve.c
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "c_functions.h"
#include "mysh.h"
#include "mysh_macros.h"
#include "mysh_structures.h"

int print_status_error(int wstatus)
{
    int ret = 0;

    if (WIFSIGNALED(wstatus)) {
        if (WTERMSIG(wstatus) == SIGSEGV) {
            my_putstr(SIGSEGV_ERROR);
            ret = RETURN_SIGSEGV;
        }
        if (WTERMSIG(wstatus) == SIGFPE) {
            my_putstr(SIGFPE_ERROR);
            ret = RETURN_SIGFPE;
        }
        if (WCOREDUMP(wstatus))
            my_putstr(CORE_DUMPED);
        else
            my_putchar('\n');
        return (ret);
    }
    return (WEXITSTATUS(wstatus));
}

int do_execve_without_path(char **command, t_minishell *minishell)
{
    pid_t pid = 0;
    int wstatus = 0;
    char **env = get_env(minishell->env);

    pid = fork();
    if (pid == 0)
        execve(command[0], command, env);
    waitpid(pid, &wstatus, 0);
    free_list(minishell->env);
    minishell->env = env_setup(env);
    my_free_array_string(env);
    return (print_status_error(wstatus));
}

int do_execve_with_path(char **command, t_minishell *minishell)
{
    char *path = get_path_bin(command[0], minishell);
    char **env = get_env(minishell->env);
    pid_t pid = 0;
    int wstatus = 0;

    pid = fork();
    if (pid == 0)
        execve(path, command, env);
    waitpid(pid, &wstatus, 0);
    free_list(minishell->env);
    minishell->env = env_setup(env);
    free(path);
    my_free_array_string(env);
    return (print_status_error(wstatus));
}

int do_execve(char **command, t_minishell *minishell)
{
    if (without_path(command[0], minishell))
        return (do_execve_with_path(command, minishell));
    else if (with_path(command[0], minishell))
        return (do_execve_without_path(command, minishell));
}