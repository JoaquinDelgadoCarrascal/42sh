/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main Function
*/

#include "mysh.h"
#include "mysh_macros.h"

int main(int argc, char **argv, char **env)
{
    if (error_handling(argc) == ERROR)
        return (ERROR);
    return (mysh(env));
}