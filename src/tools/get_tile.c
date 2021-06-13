/*
** EPITECH PROJECT, 2021
** defender
** File description:
** get_tile
*/
#include "../../include/defender.h"

sfIntRect get_tile(int tile_size, int tile_number, int width)
{
    int row = (tile_number - 1) / width;
    int col = (tile_number - 1) % width;
    sfIntRect r;

    if (tile_number <= 0)
        return r;
    return new_int_rect(tile_size, tile_size,
                        col * tile_size,
                        row * tile_size);
}