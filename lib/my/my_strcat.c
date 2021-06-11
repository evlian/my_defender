/*
** EPITECH PROJECT, 2020
** MyStrCat
** File description:
** Function that concatenates
*/
#include <unistd.h>
char *my_strcat(char *dest, char const *src);
int length(char *str);

int length(char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char *my_strcat(char *dest, char const *src)
{
    int dest_length = length(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_length + i] = src[i];
        i++;
    }
    dest[dest_length + i] = '\0';
    return dest;
}