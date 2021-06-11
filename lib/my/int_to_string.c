/*
** EPITECH PROJECT, 2021
** lib
** File description:
** int to string
*/
char *int_to_string(char *str, int num);
char *my_revstr(char *str);
#include <unistd.h>

int my_num_len(int num)
{
    int len = 1;

    while (num > 9) {
        num /= 10;
        len++;
    }
    return len;
}

char *int_to_string(char *str, int num)
{
    int i = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return str;
}