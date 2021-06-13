/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_enemies
*/
#include "../../include/defender.h"

void init_health_bar(game_instance *game)
{
    game->shapes.hp_bar = sfRectangleShape_create();
    game->shapes.hp_bar_outline = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->shapes.hp_bar,
                                new_color(54, 255, 70, 255));
    sfRectangleShape_setOutlineColor(game->shapes.hp_bar_outline,
                                new_color(0, 0, 0, 255));
    sfRectangleShape_setFillColor(game->shapes.hp_bar_outline,
                                new_color(255, 255, 255, 0));
    sfRectangleShape_setOutlineThickness(game->shapes.hp_bar_outline, 1);
    sfRectangleShape_setSize(game->shapes.hp_bar_outline,
                            new_vector_2f(23, 4));
}

void init_enemy_texture(game_instance *game)
{
    game->textures.enemies = sfTexture_createFromFile("./res/enemies.png",
                                                    NULL);
}

void add_enemy_type(game_instance *game, float speed, int health, short type)
{
    enemy *new = (enemy *) malloc(sizeof(enemy));

    new->max_health = health;
    new->next = game->enemy_types;
    new->speed = speed;
    new->type = type;
    game->enemy_types = new;
}

void init_enemy_types(game_instance *game)
{
    game->enemy_types = NULL;
    add_enemy_type(game, 1, 700, 0);
    add_enemy_type(game, 1.5, 800, 1);
    add_enemy_type(game, 2, 900, 2);
    add_enemy_type(game, 3, 500, 3);
}

void init_enemies(game_instance *game)
{
    init_health_bar(game);
    init_enemy_texture(game);
    init_enemy_types(game);
    game->enemies = NULL;
    game->sprites.enemy = sfSprite_create();
    sfSprite_setTexture(game->sprites.enemy, game->textures.enemies, sfTrue);
    game->spawn_clock = sfClock_create();
}