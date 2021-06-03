/*
** EPITECH PROJECT, 2021
** input_to_tree.c
** File description:
** input_to_tree.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh_structures.h"

bool is_char_eval_prior(t_priorities **priorities, int priority, char *cmd,
int j)
{
    for (int i = 0; priorities[i]; i++) {
        if (priority == 2 && cmd[j] == '|' && cmd[j + 1] != '|')
            return (false);
        if (priorities[i]->priority == priority &&
        priorities[i]->key[0] == cmd[j])
            return (true);
    }
    return (false);
}

bool is_char_in_cmd(t_priorities **priorities, int priority, char *cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if (is_char_eval_prior(priorities, priority, cmd, i))
            return (true);
    }
    return (false);
}

char *get_value(char *cmd, int *i)
{
    char *value = NULL;

    if (cmd[*i] == cmd[*i + 1]) {
        value = my_cut(cmd, *i, *i + 1);
        *i = *i + 1;
        return (value);
    }
    else
        return (my_ctoa(cmd[*i]));
}

t_nodebt *input_to_tree(t_priorities **priorities, int priority,
char *cmd, t_nodebt *parent)
{
    t_nodebt *root = NULL;
    char *left = NULL;
    char *right = NULL;

    cmd = my_clean_str(cmd);
    for (int i = 0; cmd[i]; i++) {
        if (is_char_eval_prior(priorities, priority, cmd, i)) {
            left = my_cut(cmd, 0, i - 1);
            root = constructor_nodebt(get_value(cmd, &i), parent);
            right = my_cut(cmd, i + 1, my_strlen(cmd));
            root->left = input_to_tree(priorities, priority, left, root);
            root->right = input_to_tree(priorities, priority, right, root);
            free(cmd);
            return (root);
        }
    }
    if (!is_char_in_cmd(priorities, priority, cmd) && priority != 5)
        return (input_to_tree(priorities, priority + 1, cmd, parent));
    else if (!is_char_in_cmd(priorities, priority, cmd) && priority == 5)
        return (constructor_nodebt(cmd, parent));
}