/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_game_over
*/
#include "../../include/defender.h"

void display_game_over(game_instance *game)
{
    sfRenderWindow_drawSprite(game->window, game->sprites.game_over, NULL);
    sfText_setPosition(game->text, new_vector_2f(300, 130));
    sfText_setCharacterSize(game->text, 35);
    sfText_setColor(game->text, sfWhite);
    display_text(game, "Your score is");
    sfText_setColor(game->text, new_color(245, 169, 98, 255));
    sfText_setPosition(game->text, new_vector_2f(630, 130));
    display_number(game, game->score);
    sfText_setColor(game->text, sfWhite);
    sfText_setPosition(game->text, new_vector_2f(150, 400));
    display_text(game, "Play again(r) | Menu(m) | Quit(q)");
}