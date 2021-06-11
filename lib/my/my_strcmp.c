/*
** EPITECH PROJECT, 2020
** MyStrCmp
** File description:
** Compare values of strings
*/
#include <unistd.h>
int my_strcmp(char const *s1, char const *s2);

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}