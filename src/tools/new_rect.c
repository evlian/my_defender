/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get rect
*/
#include "../../include/defender.h"

sfIntRect new_int_rect(int width, int height, int left, int top)
{
    sfIntRect rect;

    rect.height = height;
    rect.left = left;
    rect.top = top;
    rect.width = width;
    return rect;
}