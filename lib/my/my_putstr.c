/*
** EPITECH PROJECT, 2020
** MyPutstr
** File description:
** Function that displays chars of a string
*/
#include <unistd.h>
int my_putstr(char const *str);

int my_putstr(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    write(1, str, len);
    return 0;
}