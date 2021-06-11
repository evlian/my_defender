/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_text
*/
#include "../../include/defender.h"

void init_font(game_instance *game)
{
    game->font = sfFont_createFromFile("./res/font.ttf");
}

void init_text(game_instance *game)
{
    game->text = sfText_create();
    init_font(game);
    sfText_setFont(game->text, game->font);
    sfText_setColor(game->text, new_color(52, 71, 40, 255));
}