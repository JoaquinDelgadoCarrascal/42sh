/*
** EPITECH PROJECT, 2021
** create_binary_tree.c
** File description:
** create_binary_tree.c
*/

#include <stdlib.h>
#include "c_functions_structures.h"

t_binarytree *create_binary_tree(void)
{
    t_binarytree *bintree = malloc(sizeof(t_binarytree));

    bintree->root = NULL;
    bintree->height = 0;
    return (bintree);
}