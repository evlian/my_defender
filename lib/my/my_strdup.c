/*
** EPITECH PROJECT, 2020
** MyStrdup
** File description:
** Pain
*/
#include <stdlib.h>
char *my_strdup(char *str);
int my_strlenn(char const *str);

int my_strlenn(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char *str)
{
    char *new = malloc(sizeof(char) * my_strlenn(str) + 1);
    int i = 0;

    while (str[i] != '\0') {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return new;
}