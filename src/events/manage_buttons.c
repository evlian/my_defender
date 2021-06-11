/*
** EPITECH PROJECT, 2021
** defender
** File description:
** manage_buttons
*/
#include "../../include/defender.h"

int is_hovering(game_instance *game, button **b)
{
    int i = 0;
    int is_hovering = sfFalse;

    while (b[i] != NULL) {
        if (b[i]->state == BTN_HOVER)
            is_hovering = sfTrue;
        i++;
    }
    return is_hovering;
}

void manage_button_hover(game_instance *game, sfVector2i mouse, button **b)
{
    sfIntRect rect;
    int i = 0;

    while (b[i] != NULL) {
        rect = vector_to_rect(b[i]->position, 190, 50);
        if (sfIntRect_contains(&rect, mouse.x, mouse.y)) {
            if (b[i]->state != BTN_HOVER) {
                sfSound_play(game->sounds.hover);
            }
            b[i]->state = BTN_HOVER;
        }
        else
            b[i]->state = BTN_IDLE;
        i++;
    }
}

void manage_button_click(game_instance *game, button **b)
{
    int i = 0;

    while (b[i] != NULL) {
        if (b[i]->state == BTN_HOVER) {
            sfSound_play(game->sounds.click);
            (b[i]->on_click)(game);
        }
        i++;
    }
}