/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** Convert a string to lowercase
*/
#include <unistd.h>
char *my_strlowcase(char *str);

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] = str[i] + ' ';
        }
        i++;
    }
    return str;
}