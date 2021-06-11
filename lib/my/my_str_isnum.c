/*
** EPITECH PROJECT, 2020
** MyStrIsNum
** File description:
** Function that checks if string has any non-numerical characters
*/
#include <unistd.h>
int my_str_isnum(char const *str);

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}