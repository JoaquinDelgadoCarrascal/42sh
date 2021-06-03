/*
** EPITECH PROJECT, 2020
** my_isnum
** File description:
** check if a character is a number
*/

int my_isnum(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}