/*
** EPITECH PROJECT, 2021
** original_builtins_setup.c
** File description:
** original_builtins_setup.c
*/

#include <stdlib.h>
#include "c_functions.h"
#include "mysh_macros.h"

void original_builtins_setup_part1(char **original_builtins)
{
    original_builtins[0] = my_strdup(":");
    original_builtins[1] = my_strdup("@");
    original_builtins[2] = my_strdup("alias");
    original_builtins[3] = my_strdup("alloc");
    original_builtins[4] = my_strdup("bg");
    original_builtins[5] = my_strdup("bindkey");
    original_builtins[6] = my_strdup("break");
    original_builtins[7] = my_strdup("breaksw");
    original_builtins[8] = my_strdup("builtins");
    original_builtins[9] = my_strdup("case");
    original_builtins[10] = my_strdup("cd");
    original_builtins[11] = my_strdup("chdir");
    original_builtins[12] = my_strdup("complete");
    original_builtins[13] = my_strdup("continue");
    original_builtins[14] = my_strdup("default");
    original_builtins[15] = my_strdup("dirs");
    original_builtins[16] = my_strdup("echo");
    original_builtins[17] = my_strdup("echotc");
    original_builtins[18] = my_strdup("else");
    original_builtins[19] = my_strdup("end");
}

void original_builtins_setup_part2(char **original_builtins)
{
    original_builtins[20] = my_strdup("endif");
    original_builtins[21] = my_strdup("endsw");
    original_builtins[22] = my_strdup("eval");
    original_builtins[23] = my_strdup("exec");
    original_builtins[24] = my_strdup("exit");
    original_builtins[25] = my_strdup("fg");
    original_builtins[26] = my_strdup("filetest");
    original_builtins[27] = my_strdup("foreach");
    original_builtins[28] = my_strdup("glob");
    original_builtins[29] = my_strdup("goto");
    original_builtins[30] = my_strdup("hashstat");
    original_builtins[31] = my_strdup("history");
    original_builtins[32] = my_strdup("hup");
    original_builtins[33] = my_strdup("if");
    original_builtins[34] = my_strdup("jobs");
    original_builtins[35] = my_strdup("kill");
    original_builtins[36] = my_strdup("limit");
    original_builtins[37] = my_strdup("log");
    original_builtins[38] = my_strdup("login");
    original_builtins[39] = my_strdup("logout");
}

void original_builtins_setup_part3(char **original_builtins)
{
    original_builtins[40] = my_strdup("ls-F");
    original_builtins[41] = my_strdup("nice");
    original_builtins[42] = my_strdup("nohup");
    original_builtins[43] = my_strdup("notify");
    original_builtins[44] = my_strdup("onintr");
    original_builtins[45] = my_strdup("popd");
    original_builtins[46] = my_strdup("printenv");
    original_builtins[47] = my_strdup("pushd");
    original_builtins[48] = my_strdup("rehash");
    original_builtins[49] = my_strdup("repeat");
    original_builtins[50] = my_strdup("sched");
    original_builtins[51] = my_strdup("set");
    original_builtins[52] = my_strdup("setenv");
    original_builtins[53] = my_strdup("settc");
    original_builtins[54] = my_strdup("setty");
    original_builtins[55] = my_strdup("shift");
    original_builtins[56] = my_strdup("source");
    original_builtins[57] = my_strdup("stop");
    original_builtins[58] = my_strdup("suspend");
    original_builtins[59] = my_strdup("switch");
}

void original_builtins_setup_part4(char **original_builtins)
{
    original_builtins[60] = my_strdup("telltc");
    original_builtins[61] = my_strdup("termname");
    original_builtins[62] = my_strdup("time");
    original_builtins[63] = my_strdup("umask");
    original_builtins[64] = my_strdup("unalias");
    original_builtins[65] = my_strdup("uncomplete");
    original_builtins[66] = my_strdup("unhash");
    original_builtins[67] = my_strdup("unlimit");
    original_builtins[68] = my_strdup("unset");
    original_builtins[69] = my_strdup("unsetenv");
    original_builtins[70] = my_strdup("wait");
    original_builtins[71] = my_strdup("where");
    original_builtins[72] = my_strdup("which");
    original_builtins[73] = my_strdup("while");
    original_builtins[74] = NULL;
}

char **original_builtins_setup(void)
{
    char **original_builtins = malloc((TOTAL_ORIGINAL_BUILTINS + 1)
    * sizeof(char *));
    original_builtins_setup_part1(original_builtins);
    original_builtins_setup_part2(original_builtins);
    original_builtins_setup_part3(original_builtins);
    original_builtins_setup_part4(original_builtins);
    return (original_builtins);
}