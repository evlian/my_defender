/*
** EPITECH PROJECT, 2021
** defender
** File description:
** destroy_sprites
*/
#include "../../include/defender.h"

void destroy_sprites(game_instance *game)
{
    sfSprite_destroy(game->sprites.bullet);
    sfSprite_destroy(game->sprites.button);
    sfSprite_destroy(game->sprites.coin);
    sfSprite_destroy(game->sprites.enemy);
    sfSprite_destroy(game->sprites.game_over);
    sfSprite_destroy(game->sprites.intro);
    sfSprite_destroy(game->sprites.tower);
}