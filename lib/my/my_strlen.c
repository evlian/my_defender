/*
** EPITECH PROJECT, 2020
** MyStrLen
** File description:
** Function that counts and returns the number of chars in a string
*/
#include <unistd.h>
int my_strlen(char const *str);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}