/*
** EPITECH PROJECT, 2020
** MySwap
** File description:
** Swaps the content of two integers
*/
#include <unistd.h>
void my_swap(int *a, int *b);

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}