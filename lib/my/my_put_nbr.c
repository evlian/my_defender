/*
** EPITECH PROJECT, 2020
** MyPutNbr
** File description:
** Function that displays number given as parameter
*/
#include <unistd.h>
int my_put_nbr(int nb);

int my_put_nbr(int nb)
{
    char c;

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    c = (nb % 10) + '0';
    write(1, &c, 1);
}