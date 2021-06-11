/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_enemies
*/
#include "../../include/defender.h"

void init_health_bar(game_instance *game)
{
    game->shapes.health_bar = sfRectangleShape_create();
    game->shapes.health_bar_outline = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->shapes.health_bar, new_color(54, 255, 70, 255));
    sfRectangleShape_setOutlineColor(game->shapes.health_bar_outline, new_color(0, 0, 0, 255));
    sfRectangleShape_setOutlineThickness(game->shapes.health_bar_outline, 1);
    sfRectangleShape_setSize(game->shapes.health_bar_outline, new_vector_2f(23, 4));
}

void init_enemy_texture(game_instance *game)
{
    game->textures.enemies = sfTexture_createFromFile("./res/characters/enemy_1.png", NULL);
}

void init_enemies(game_instance *game)
{
    init_health_bar(game);
    init_enemy_texture(game);
    game->enemies = NULL;
    game->sprites.enemy = sfSprite_create();
    sfSprite_setTexture(game->sprites.enemy, game->textures.enemies, sfTrue);
    game->spawn_clock = sfClock_create();
}