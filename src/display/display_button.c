/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_button
*/
#include "../../include/defender.h"

void display_button(game_instance *game, button *button)
{
    sfIntRect rect = new_int_rect(190, 49, 0, 0);
    sfVector2f pos = button->position;

    pos.x += 10;
    if (button->state == BTN_HOVER) {
        pos.y += 4;
        rect.top = 49;
    }
    sfText_setString(game->text, button->text);
    if (my_strlen(sfText_getString(game->text)) > 9) {
        sfText_setCharacterSize(game->text, 19);
        pos.y += 4;
    }
    else
        sfText_setCharacterSize(game->text, 25);
    sfText_setPosition(game->text, pos);
    sfSprite_setPosition(game->sprites.button, button->position);
    sfSprite_setTextureRect(game->sprites.button, rect);
    sfText_setColor(game->text, new_color(215, 215, 215, 255));
    sfRenderWindow_drawSprite(game->window, game->sprites.button, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}