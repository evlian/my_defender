/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** Lib
*/
#include <stdlib.h>
#include "../../include/my.h"
char *my_realloc(char *str, int new_length);

char *my_realloc(char *str, int new_length)
{
    char *temp = malloc(sizeof(char) * new_length + 2);
    temp = my_strcpy(temp, str);
    temp[new_length + 1] = '\0';
    free(str);
    return temp;
}