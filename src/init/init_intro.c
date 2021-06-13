/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_intro
*/
#include "../../include/defender.h"

void init_intro(game_instance *game)
{
    game->textures.intro = sfTexture_createFromFile("./res/intro.jpg", NULL);
    game->sprites.intro = sfSprite_create();
    sfSprite_setTexture(game->sprites.intro, game->textures.intro, sfTrue);
    sfSprite_setScale(game->sprites.intro, new_vector_2f(0.2, 0.2));
    sfSprite_setPosition(game->sprites.intro, new_vector_2f(W_WIDTH / 2.0,
                                                        W_HEIGHT / 2.0));
}