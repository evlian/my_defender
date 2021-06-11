/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** Function that capitalizes the first letter every word of a string
*/
#include <unistd.h>
char *my_strlowcase2(char *str);
char *my_strcapitalize(char *str);

char *my_strlowcase2(char *str)
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

char *my_strcapitalize(char *str)
{
    int i = 0;
    char c;
    char b = 32;
    my_strlowcase2(str);

    while (str[i] != '\0') {
        c = str[i];
        if (b > 31 && b < 48  && c >= 'a' && c <= 'z')
            str[i] = c - ' ';
        i++;
        b = str[i - 1];
    }
    return str;
}