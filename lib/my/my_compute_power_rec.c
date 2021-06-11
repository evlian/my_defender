/*
** EPITECH PROJECT, 2020
** MyComputePowerRec
** File description:
** Recursive function that returns power of a number
*/
#include <unistd.h>
int my_compute_power_rec(int nb, int p);

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        nb *= my_compute_power_rec(nb, p - 1);
    }
    return nb;
}