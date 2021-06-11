/*
** EPITECH PROJECT, 2020
** MyStrIsLower
** File description:
** Function that checks if string has any lowercase characters
*/
#include <unistd.h>
int my_str_islower(char const *str);

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'a' || str[i] > 'z') {
            return 0;
        }
        i++;
    }
    return 1;
}