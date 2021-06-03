/*
** EPITECH PROJECT, 2021
** c_functions_structures.h
** File description:
** c_functions_structures.h
*/

#ifndef C_FUNCTIONS_STRUCTURES_H
#define C_FUNCTIONS_STRUCTURES_H

typedef struct s_info_node {
    char *var_name;
    char *var_value;
} t_info_node;

//LINKED_LIST

typedef struct s_nodell {
    t_info_node *info;
    struct s_nodell *prev;
    struct s_nodell *next;
} t_nodell;

typedef struct s_list {
    t_nodell *head;
    t_nodell *last;
    int size;
} t_list;

//BINARY_TREE

typedef struct s_nodebt {
    char *value;
    struct s_nodebt *left;
    struct s_nodebt *right;
    struct s_nodebt *parent;
} t_nodebt;

typedef struct s_binarytree {
    t_nodebt *root;
    int height;
} t_binarytree;

#endif /* !C_FUNCTIONS_STRUCTURES_H */