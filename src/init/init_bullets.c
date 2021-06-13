/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_bullets
*/
#include "../../include/defender.h"

void init_laser(game_instance *game)
{
    game->shapes.laser = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(game->shapes.laser, sfLines);
    game->shapes.point_one.color = sfRed;
    game->shapes.point_two.color = sfRed;
}

void init_bullets(game_instance *game)
{
    bullet *b = (bullet *) malloc(sizeof(bullet));
    bullet *a = (bullet *) malloc(sizeof(bullet));

    game->sprites.bullet = sfSprite_create();
    sfSprite_setTexture(game->sprites.bullet, game->tileset.texture, sfTrue);
    init_laser(game);
    game->bullets = NULL;
    game->bullet_types = NULL;
    a->texture_rect = new_int_rect(32, 32, 22 * 32, 11 * 32);
    b->texture_rect = new_int_rect(32, 32, 19 * 32, 11 * 32);
    b->attack_time = 0.5;
    b->next = game->bullet_types;
    game->bullet_types = b;
    a->next = game->bullet_types;
    game->bullet_types = a;
    game->tower_choices->bullet = b;
    game->tower_choices->next->next->bullet = a;
}