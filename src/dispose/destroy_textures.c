/*
** EPITECH PROJECT, 2021
** defender
** File description:
** destroy_textures
*/
#include "../../include/defender.h"

void destroy_textures(game_instance *game)
{
    sfTexture_destroy(game->textures.coin);
    sfTexture_destroy(game->textures.enemies);
    sfTexture_destroy(game->textures.game_over);
    sfTexture_destroy(game->textures.intro);
    sfTexture_destroy(game->textures.ui);
    sfTexture_destroy(game->tileset.texture);
}