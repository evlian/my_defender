/*
** EPITECH PROJECT, 2020
** MyGetNbr
** File description:
** Function that converts a string to a number
*/
#include <unistd.h>
int my_getnbr(char const *str);

int my_getnbr(char const *str)
{
    int i = 0;
    long number = 0;
    int neg_multiplier = 1;
    int has_num = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            neg_multiplier = -1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - '0');
            has_num = 1;
        } else {
            if (has_num == 1)
                break;
        }
        i++;
        if (number < -2147483648 || number > 2147483647) {
            return 0;
        }
    }
    return number * neg_multiplier;
}