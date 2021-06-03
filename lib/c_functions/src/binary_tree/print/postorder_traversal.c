/*
** EPITECH PROJECT, 2021
** postorder_traversal.c
** File description:
** postorder_traversal.c
*/

#include <stdio.h>
#include "c_functions_structures.h"

void print_postoder_traversal(t_nodebt *root)
{
    if (root) {
        print_postoder_traversal(root->left);
        print_postoder_traversal(root->right);
        printf("%s -> ", root->value);
    }
}

void postoder_traversal(t_binarytree *bintree)
{
    if (bintree && bintree->root) {
        print_postoder_traversal(bintree->root);
        printf("\n");
    }
}