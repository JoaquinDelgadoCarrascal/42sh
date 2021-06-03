/*
** EPITECH PROJECT, 2021
** preorder_traversal.c
** File description:
** preorder_traversal.c
*/

#include <stdio.h>
#include "c_functions_structures.h"

void print_preoder_traversal(t_nodebt *root)
{
    if (root) {
        printf("%s -> ", root->value);
        print_preoder_traversal(root->left);
        print_preoder_traversal(root->right);
    }
}

void preoder_traversal(t_binarytree *bintree)
{
    if (bintree && bintree->root) {
        print_preoder_traversal(bintree->root);
        printf("\n");
    }
}