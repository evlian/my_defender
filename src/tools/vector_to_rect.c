/*
** EPITECH PROJECT, 2021
** tools
** File description:
** vector_to_rect
*/
#include "../../include/defender.h"

sfIntRect vector_to_rect(sfVector2f pos, int w, int h)
{
    sfIntRect rect;

    rect.width = w;
    rect.height = h;
    rect.top = pos.y;
    rect.left = pos.x;
    return rect;
}