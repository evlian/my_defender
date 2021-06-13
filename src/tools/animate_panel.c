/*
** EPITECH PROJECT, 2021
** defender
** File description:
** animate_panel
*/
#include "../../include/defender.h"

void animate_panel(game_instance *game, sfRectangleShape *r)
{
    sfFloatRect bounds;
    float w;
    float h;
    sfVector2f pos;

    sfRectangleShape_scale(r, new_vector_2f(1.1, 1.1));
    bounds = sfRectangleShape_getGlobalBounds(r);
    w = (W_WIDTH / 2.0) - (bounds.width / 2.0);
    h = (W_HEIGHT / 2.0) - (bounds.height / 2.0);
    pos = new_vector_2f(w, h);
    sfRectangleShape_setPosition(r, pos);
}