/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_money
*/
#include "../../include/defender.h"

void init_money(game_instance *game)
{
    game->textures.coin = sfTexture_createFromFile("./res/coin.png", NULL);
    game->sprites.coin = sfSprite_create();
    sfSprite_setTexture(game->sprites.coin, game->textures.coin, sfTrue);
    sfSprite_setPosition(game->sprites.coin, new_vector_2f(10, W_HEIGHT - 50));
}