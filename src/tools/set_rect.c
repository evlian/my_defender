/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** set_rect
*/
#include "../../include/defender.h"

void set_int_rect(sfIntRect *rect, int width, int height, int left, int top)
{
    if (height != NO_ARG)
        rect->height = height;
    if (left != NO_ARG)
        rect->left = left;
    if (top != NO_ARG)
        rect->top = top;
    if (width != NO_ARG)
        rect->width = width;
}