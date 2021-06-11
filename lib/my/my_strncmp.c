/*
** EPITECH PROJECT, 2020
** MyStrnCmp
** File description:
** Program that compares string values up to n
*/
#include <unistd.h>
int str_value_n(char const *str, int n);
int my_strncmp(char const *s1, char const *s2, int n);

int str_value_n(char const *str, int n)
{
    int i = 0;
    int value = 0;

    while (str[i] != '\0' && i < n) {
        value += str[i];
        i++;
    }
    return value;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int s1_value = str_value_n(s1, n);
    int s2_value = str_value_n(s2, n);

    if (s1_value > s2_value)
        return 1;
    else if (s1_value < s2_value)
        return -1;
    else
        return 0;
}