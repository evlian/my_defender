/*
** EPITECH PROJECT, 2020
** My_Strncpy
** File description:
** Function that copies n characters of a string to another
*/
#include <unistd.h>
char *my_strncpy(char *dest, char const *src, int n);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return dest;
}