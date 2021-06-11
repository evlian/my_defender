/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_tilemap
*/
#include "../../include/defender.h"

void display_tower_radius(game_instance *game)
{
    sfVector2f pos = game->selected_tower->position;
    int radius = game->selected_tower->radius;

    if (pos.x == -1)
        return;
    pos.x -= (radius - 16);
    pos.y -= (radius - 16);
    sfCircleShape_setRadius(game->shapes.radius, radius);
    sfCircleShape_setPosition(game->shapes.radius, pos);
    sfRenderWindow_drawCircleShape(game->window, game->shapes.radius, NULL);
}

void display_selected_tower(game_instance *game, tile tile)
{
    if (!game->build_mode)
        return;
    if (tile.is_selected) {
        sfSprite_setTextureRect(game->tilemap.tile_sprite, game->selected_tower->texture);
        if (tile.is_tower_host)
            sfSprite_setColor(game->tilemap.tile_sprite, sfGreen);
        else
            sfSprite_setColor(game->tilemap.tile_sprite, sfRed);
        sfRenderWindow_drawSprite(game->window, game->tilemap.tile_sprite, NULL);
        sfSprite_setColor(game->tilemap.tile_sprite, sfWhite);
    }
}

void display_tilemap(game_instance *game)
{
    int i = 0;
    int j = 0;

    while (i < game->tilemap.rows) {
        j = 0;
        while (j < game->tilemap.cols) {
            sfSprite_setTextureRect(game->tilemap.tile_sprite, game->tilemap.layer1[i][j].rect);
            sfSprite_setPosition(game->tilemap.tile_sprite, new_vector_2f(j * 32, i * 32));
            sfRenderWindow_drawSprite(game->window, game->tilemap.tile_sprite, NULL);
            sfSprite_setTextureRect(game->tilemap.tile_sprite, game->tilemap.layer2[i][j].rect);
            sfRenderWindow_drawSprite(game->window, game->tilemap.tile_sprite, NULL);
            display_selected_tower(game, game->tilemap.layer1[i][j]);
            j++;
        }
        i++;
    }
}