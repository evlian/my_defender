/*
** EPITECH PROJECT, 2020
** MyStrIsPrintable
** File description:
** Function that checks if string has any non-printable characters
*/
#include <unistd.h>
int my_str_isprintable(char const *str);

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32) {
            return 0;
        }
        i++;
    }
    return 1;
}