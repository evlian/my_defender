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
    int len = my_strlen(button->text);

    pos.x += 10;
    pos.y += (button->state == BTN_HOVER) ? 4 : 0;
    rect.top = (button->state == BTN_HOVER) ? 49 : 0;
    pos.y += (len > 9) ? 4 : 0;
    sfText_setCharacterSize(game->text, (len > 9) ? 19 : 25);
    sfText_setString(game->text, button->text);
    sfText_setPosition(game->text, pos);
    sfSprite_setPosition(game->sprites.button, button->position);
    sfSprite_setTextureRect(game->sprites.button, rect);
    sfText_setColor(game->text, new_color(215, 215, 215, 255));
    sfRenderWindow_drawSprite(game->window, game->sprites.button, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}