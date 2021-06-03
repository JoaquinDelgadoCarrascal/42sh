/*
** EPITECH PROJECT, 2021
** get_tree.c
** File description:
** get_tree.c
*/

#include <stddef.h>
#include "c_functions.h"
#include "c_functions_structures.h"
#include "mysh.h"
#include "mysh_structures.h"

t_binarytree *get_tree(t_minishell *minishell, char *input)
{
    t_binarytree *bintree = NULL;

    if (!input)
        return (NULL);
    bintree = create_binary_tree();
    bintree->root = input_to_tree(minishell->priorities, 1, input, NULL);
    return (bintree);
}