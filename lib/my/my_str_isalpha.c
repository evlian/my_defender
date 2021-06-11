/*
** EPITECH PROJECT, 2020
** MyStrIsAlpha
** File description:
** Function that checks if string has any non-alphabetical characters
*/
#include <unistd.h>
int my_str_isalpha(char const *str);

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')) {
            return 0;
        }
        i++;
    }
    return 1;
}