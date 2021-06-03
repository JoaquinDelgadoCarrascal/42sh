/*
** EPITECH PROJECT, 2021
** mysh_macros.h
** File description:
** mysh_macros.h
*/

#ifndef MYSH_MACROS_
#define MYSH_MACROS_

//RETURNS
#define ERROR 84
#define SUCCESSFUL 0

//UTILS
#define HELP_FLAG "-h"
#define ERROR_MESSAGE "[ERROR]: arguments not allowed\n"
#define DEL_ENV '='
#define DEL_ATRIB ":"
#define PATH "PATH"
#define NOT_FOUND "NOT FOUND"
#define COMMAND_NOT_FOUND ": Command not found.\n"
#define PERMISSION_DENIED ": Permission denied.\n"
#define NUM_ERROR_PERMISSION_DENIED 13
#define DEVNULL "/dev/null"

//CONTROLLED_COMMANDS
#define CD "cd"
#define SETENV "setenv"
#define UNSETENV "unsetenv"
#define ENV "env"
#define EXIT "exit"
#define REPEAT "repeat"
#define HISTORY "history"
#define FOREACH "foreach"
#define ALIAS "alias"
#define IF "if"
#define WHERE "where"
#define WHICH "which"
#define NUM_COMMANDS 12
#define INDEX_EXIT 4

//ERROR_HANDLING
#define SIGSEGV_ERROR "Segmentation fault"
#define SIGFPE_ERROR "Floating exception"
#define CORE_DUMPED " (core dumped)\n"
#define RETURN_SIGSEGV 139
#define RETURN_SIGFPE 136

//PROMPT
#define PROMPT "$> "
#define CHAR_DOUBLE_IN "? "

//EXIT
#define EXIT_EX_SYNTAX "exit: Expression Syntax.\n"
#define EXIT_BAD_FORMED "exit: Badly formed number.\n"

//SETENV
#define SETENV_CMD "setenv: "
#define SETENV_TOO_MANY "Too many arguments.\n"
#define SETENV_ALPHANUM "Variable name must contain alphanumeric characters.\n"
#define SETENV_START_NUM "Variable name must begin with a letter.\n"

//UNSETENV
#define UNSETENV_TOO_FEW "unsetenv: Too few arguments.\n"

//REPEAT
#define REPEAT_TOO_FER "repeat: Too few arguments.\n"
#define REPEAT_BADLY "repeat: Badly formed number.\n"

//CD
#define CD_TOO_MANY "cd: Too many arguments.\n"
#define CD_NO_EXISTS ": No such file or directory.\n"
#define CD_NO_DIR ": Not a directory.\n"

//WHICH
#define WHICH_TOO_FEW "which: Too few arguments.\n"

//WHERE
#define WHERE_TOO_FEW "where: Too few arguments.\n"
#define WHERE_ALIASED " is aliased to "
#define WHERE_BUILTIN " is a shell built-in\n"

//REDIRECTION
#define NO_REDIRECTION "Missing name for redirect.\n"
#define TOO_LONG_NAME ": File name too long.\n"
#define FILE_NO_EXIST ": No such file or directory.\n"
#define AMBIGUOUS_REDIRECTION "Ambiguous output redirect.\n"
#define NULL_REDIRECTION "Invalid null command.\n"

//RETURN_VALUES
#define TRUE_RETURN 0
#define FALSE_RETURN 1

//COLORS
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define WHT "\e[0;37m"
#define BHWHT "\e[1;97m"
#define COLOR_RESET "\e[0m"

#endif /* !MYSH_MACROS_ */