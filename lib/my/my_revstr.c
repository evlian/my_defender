/*
** EPITECH PROJECT, 2020
** MyRevStr
** File description:
** Function that reverses a string
*/
#include <unistd.h>
int rev_str_len(char *str);
char *my_revstr(char *str);

int rev_str_len(char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char *my_revstr(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + rev_str_len(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}