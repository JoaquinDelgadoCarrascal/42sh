/*
** EPITECH PROJECT, 2021
** inoder_traversal.c
** File description:
** inoder_traversal.c
*/

#include <stdio.h>
#include "c_functions_structures.h"

void print_inoder_traversal(t_nodebt *root)
{
    if (root) {
        print_inoder_traversal(root->left);
        printf("%s -> ", root->value);
        print_inoder_traversal(root->right);
    }
}

void inoder_traversal(t_binarytree *bintree)
{
    if (bintree && bintree->root) {
        print_inoder_traversal(bintree->root);
        printf("\n");
    }
}