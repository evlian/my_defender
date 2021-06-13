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

int is_host(int x, int y)
{
    return (x == 232 && y == 0);
}

void load_tilemap(game_instance *game)
{
    int **layer1 = csv_to_array("./res/tilemap_layer_1.csv");
    int **layer2 = csv_to_array("./res/tilemap_layer_2.csv");
    int i = 0;
    int j = 0;

    while (i < game->tilemap.rows) {
        j = 0;
        while (j < game->tilemap.cols) {
            game->tilemap.layer1[i][j].rect =
                get_tile(game->tileset.tile_size, layer1[i][j], 23);
            game->tilemap.layer2[i][j].rect =
                get_tile(game->tileset.tile_size, layer2[i][j], 23);
            game->tilemap.layer1[i][j].is_tower_host =
                is_host(layer1[i][j], layer2[i][j]);
            game->tilemap.layer1[i][j].is_path = (layer1[i][j] == 258);
            j++;
        }
        i++;
    }
}

void init_tilemap(game_instance *game)
{
    game->tileset.texture = sfTexture_createFromFile("./res/tileset.png",
                                                    NULL);
    game->tilemap.tile_sprite = sfSprite_create();
    sfSprite_setTexture(game->tilemap.tile_sprite,
                        game->tileset.texture, sfTrue);
    game->tilemap.rows = 18;
    game->tilemap.cols = 32;
    game->tileset.tile_size = 32;
    game->tileset.size = 23;
    game->tilemap.layer1 = new_tilemap(game->tilemap.rows, game->tilemap.cols);
    game->tilemap.layer2 = new_tilemap(game->tilemap.rows, game->tilemap.cols);
    set_vector_2i(&game->tilemap.last_selected, 0, 0);
    load_tilemap(game);
}