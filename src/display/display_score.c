/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_score
*/
#include "../../include/defender.h"

void display_level(game_instance *game)
{
    sfText_setColor(game->text, new_color(28,31,33, 255));
    sfText_setCharacterSize(game->text, 20);
    sfText_setPosition(game->text,  new_vector_2f(W_WIDTH / 2 - 80, 10));
    display_text(game, "SCORE");
    sfText_setPosition(game->text, new_vector_2f(W_WIDTH / 2 + 10, 10));
    display_number(game, game->score);
}