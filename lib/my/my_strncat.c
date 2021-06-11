/*
** EPITECH PROJECT, 2020
** MyStrnCat
** File description:
** Concatenate a string
*/
#include <unistd.h>
char *my_strncat(char *dest, char const *src, int nb);
int len(char *str);

int len(char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_len = len(dest);

    while (i < nb && src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}