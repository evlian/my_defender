/*
** EPITECH PROJECT, 2020
** MyIsPrime
** File description:
** Function to find prime numbers
*/
#include <unistd.h>
int is_prime(int nb);
int my_find_prime_sup(int nb);

int is_prime(int nb)
{
    int i = 2;
    if (nb < 2) {
        return 0;
    }
    while (i <= (nb / 2)) {
        if ((nb % i) == 0) {
            return 0;
        } else {
            i++;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    while (is_prime(nb) == 0) {
        nb++;
    }
    return nb;
}