/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_game_over
*/
#include "../../include/defender.h"

void init_game_over(game_instance *game)
{
    game->textures.game_over = sfTexture_createFromFile("./res/game_over.jpg", NULL);
    game->sprites.game_over = sfSprite_create();
    sfSprite_setTexture(game->sprites.game_over, game->textures.game_over, sfTrue);
}