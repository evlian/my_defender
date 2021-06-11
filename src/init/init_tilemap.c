/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_tilemap
*/
#include "../../include/defender.h"

tile **new_tilemap(int rows, int cols)
{
    tile **map;
    int i = 0;
    int j = 0;

    map = (tile **) malloc(sizeof(tile *) * rows);
    while (i < rows) {
        j = 0;
        map[i] = (tile *) malloc(sizeof(tile) * cols);
        while (j < cols) {
            map[i][j].rect = new_int_rect(0,0,0,0);
            map[i][j].is_selected = 0;
            j++;
        }
        i++;
    }
    return map;
}

void load_tilemap(game_instance *game)
{
    int **layer1 = csv_to_array("./res/tilemap_layer_1.csv");
    int **layer2 = csv_to_array("./res/tilemap_layer_2.csv");
    int i = 0;
    int j = 0;
    int x;
    int y;

    while (i < game->tilemap.rows) {
        j = 0;
        while (j < game->tilemap.cols) {
            x = layer1[i][j];
            y = layer2[i][j];
            if (x > 0)
                game->tilemap.layer1[i][j].rect = get_tile(game->tileset.tile_size, x, 23);
            if (y > 0)
                game->tilemap.layer2[i][j].rect = get_tile(game->tileset.tile_size, y, 23);
            if (x == 232 && y == 0)
                game->tilemap.layer1[i][j].is_tower_host = sfTrue;
            else
                game->tilemap.layer1[i][j].is_tower_host = sfFalse;
            if (x == 258)
                game->tilemap.layer1[i][j].is_path = sfTrue;
            else
                game->tilemap.layer1[i][j].is_path = sfFalse;
            j++;
        }
        i++;
    }
}

void init_tilemap(game_instance *game)
{
    game->tileset.tileset = sfTexture_createFromFile("./res/tileset.png", NULL);
    game->tilemap.tile_sprite = sfSprite_create();
    sfSprite_setTexture(game->tilemap.tile_sprite, game->tileset.tileset, sfTrue);
    game->tilemap.rows = 18;
    game->tilemap.cols = 32;
    game->tileset.tile_size = 32;
    game->tileset.size = 23;
    game->tilemap.layer1 = new_tilemap(game->tilemap.rows, game->tilemap.cols);
    game->tilemap.layer2 = new_tilemap(game->tilemap.rows, game->tilemap.cols);
    set_vector_2i(&game->tilemap.last_selected, 0, 0);
    load_tilemap(game);
}