/*
** EPITECH PROJECT, 2018
** MyStrUpCase
** File description:
** Function that converts string into uppercase
*/
#include <unistd.h>
char len3(char *str);
char *my_strupcase(char *str);

char len3(char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char *my_strupcase(char *str)
{
    int length = len3(str);
    int i = 0;

    while (i < length) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        i++;
    }
    return str;
}