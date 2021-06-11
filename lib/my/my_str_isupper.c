/*
** EPITECH PROJECT, 2020
** MyStrIsUpper
** File description:
** Function that checks if string has any uppercase characters
*/
#include <unistd.h>
int my_str_isupper(char const *str);

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z') {
            return 0;
        }
        i++;
    }
    return 1;
}