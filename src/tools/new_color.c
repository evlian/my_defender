/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get color
*/
#include "../../include/defender.h"

sfColor new_color(int r, int g, int b, int a)
{
    sfColor color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}