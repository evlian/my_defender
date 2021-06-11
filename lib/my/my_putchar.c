/*
** EPITECH PROJECT, 2020
** MyPutChar
** File description:
** Function that prints chars
*/
#include <unistd.h>
void my_putchar(char c);

void my_putchar(char c)
{
    write(1, &c, 1);
}