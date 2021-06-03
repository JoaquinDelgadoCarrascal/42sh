/*
** EPITECH PROJECT, 2021
** free_bintree.c
** File description:
** free_bintree.c
*/

#include <stdlib.h>
#include "c_functions_structures.h"

void free_branches(t_nodebt *node)
{
    if (node) {
        free(node->value);
        free_branches(node->left);
        free_branches(node->right);
        free(node);
    }
}

void free_bintree(t_binarytree *bintree)
{
    if (bintree) {
        free_branches(bintree->root);
        free(bintree);
    }
}