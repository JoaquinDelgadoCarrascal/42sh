/*
** EPITECH PROJECT, 2021
** mysh.h
** File description:
** mysh.h
*/

#ifndef MYSH_
#define MYSH_

#include <stdio.h>
#include "mysh_structures.h"

//MAIN_FUNCTION
int mysh(char **);

//UTILS
int print_error(char *);
int get_index_of_var(t_list *, char *);
char *get_value_in_index(t_list *, int);
char *get_name_in_index(t_list *, int);
char *set_value_in_index(t_list *, int, char *);
bool my_str_isalphanum(char *);
void print_env(t_list *);
void print_exit(void);
void free_minishell(t_minishell *);
void free_foreach(t_foreach *);
char *substitute_key(char *, char *, char *);
char *get_input_inhib(void);
int count_args(char **);
int my_isnum(char *);
char *move_left(char *, int);

//ERROR_HANDLING
int error_handling(int);
int error_handling_in_redirection(char *);
int error_handling_output_redirection(char *);
bool check_foreach(char **);
int check_if_errors(char **, t_minishell *);
int check_if_operators(char *, bool, bool);

//SETUP
t_minishell *minishell_setup(char **);
t_list *env_setup(char **);
t_builtin **builtin_setup(void);
t_list *env_setup(char **);
t_priorities **priorities_setup(void);
void command_execution(t_nodebt *, t_minishell *);
int exec_command(char **, t_minishell *);
char **original_builtins_setup(void);

//BUILTIN_FUNCTIONS
int exec_exit(char **, t_minishell *);
int exec_setenv(char **, t_minishell *);
int print_error_setenv(char *);
int exec_env(char **, t_minishell *);
int exec_unsetenv(char **, t_minishell *);
int exec_cd(char **, t_minishell *);
int exec_repeat(char **, t_minishell *);
int do_builtin(char **, t_minishell *);
int exec_history(char **, t_minishell *);
int exec_alias(char **, t_minishell *);
int exec_if(char **, t_minishell *);
int exec_foreach(char **, t_minishell *);
int exec_where(char **, t_minishell *);
int exec_which(char **, t_minishell *);
void add_input_to_history(t_minishell *, char *);

//ALIAS
int do_alias(char **, t_minishell *);
char *arr_to_str(char **);
char *get_alias_value(char **);
int get_index_alias(char *, t_list *);
void print_alias(t_list *);
void print_value_alias(char *, t_list *);
void add_to_alias(char **, t_minishell *);
void change_alias(char **, t_minishell *);

//WHICH
void which_alias(char *, t_minishell *);
void which_builtin(char *, t_minishell *);
void print_which(char *, t_minishell *);

//WHERE
void where_alias(char *, t_minishell *);
void where_builtin(char *, t_minishell *);
void print_where(char *, t_minishell *);

//IF
char *get_if_command(char **, int);
char **remove_parenthesis(char **);
int find_parenthesis(char **, char *);
int check_parenthesis(char **, int);
int print_if_error(char *);

//CD_BUILTIN
bool is_special(char **);
bool is_dir(const char *);
bool is_reg(const char *);

//MINISHELL > UTILS
char *get_path_bin(char *, t_minishell *);
char *get_path_value(t_minishell *);
char **get_env(t_list *);
char **get_command(char *);
bool is_builtin(char **, t_minishell *);
bool is_existing_command(char *, t_minishell *);
bool is_alias(char **, t_minishell *);
int do_execve(char **, t_minishell *);
void print_prompt(t_minishell *);
bool with_path(char *, t_minishell *);
bool without_path(char *, t_minishell *);
void print_content_file(FILE *);
char *get_value_in_redirection(t_nodebt *);
char *get_hour(void);
bool is_permission_denied(char *);
char **transform_arguments(char **);

//BINTREE
t_nodebt *input_to_tree(t_priorities **, int, char *, t_nodebt *);
void command_execution(t_nodebt *, t_minishell *);
bool is_node_priority(t_nodebt *, t_priorities **);
t_binarytree *get_tree(t_minishell *, char *);
void exec_tree(t_nodebt *, t_minishell *);
void tree_execution(t_minishell *);

//ERROR_HANDLING_BINTREE
int error_handling_tree(t_nodebt *, t_minishell *);
int check_redirection(t_nodebt *, t_minishell *);
int error_handling_pipe(t_nodebt *, t_minishell *);
int check_pipe(t_nodebt *);
int error_handling_double_and(t_nodebt *, t_minishell *);
int error_handling_double_or(t_nodebt *, t_minishell *);

//ERROR_HANDLING_BINTREE > UTILS
bool is_redirection(t_nodebt *, t_minishell *);
bool is_semicolon(t_nodebt *);
bool is_pipe(t_nodebt *);
bool is_double_and(t_nodebt *);
bool is_double_or(t_nodebt *);

//REDIRECTIONS
void double_out_redirection(t_nodebt *, t_minishell *);
void double_in_redirection(t_nodebt *, t_minishell *);
FILE *pipeit(FILE *, t_nodebt *, t_minishell *);
void pipeit_exec(t_nodebt *, t_minishell *);
void simple_in_redirection(t_nodebt *, t_minishell *);
void simple_out_redirection(t_nodebt *, t_minishell *);
void double_and(t_nodebt *, t_minishell *);
void double_or(t_nodebt *, t_minishell *);
void semicolon(t_nodebt *, t_minishell *);

#endif /* !MYSH_ */