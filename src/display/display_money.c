/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_money
*/
#include "../../include/defender.h"

void display_money(game_instance *game)
{
    sfRenderWindow_drawSprite(game->window, game->sprites.coin, NULL);
    sfText_setColor(game->text, new_color(243, 199, 13, 255));
    sfText_setCharacterSize(game->text, 20);
    sfText_setPosition(game->text, new_vector_2f(70, 535));
    display_text(game, "$");
    sfText_setPosition(game->text, new_vector_2f(90, 535));
    display_number(game, game->money);
}