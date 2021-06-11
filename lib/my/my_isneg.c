/*
** EPITECH PROJECT, 2020
** MyIsNeg
** File description:
** Function to determine if number is negative or positive .
*/
#include <unistd.h>
int my_isneg(int n);

int my_isneg(int n)
{
    char c;

    if (n < 0) {
        c = 'N';
    } else {
        c = 'P';
    }
    write(1, &c, 1);
    return 0;
}