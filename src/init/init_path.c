/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_path
*/
#include "../../include/defender.h"

void init_path(game_instance *game)
{
    int path[7] = {DIR_DOWN, DIR_RIGHT,
                    DIR_DOWN, DIR_RIGHT,
                    DIR_UP, DIR_RIGHT, DIR_DOWN};
    int i = 0;
    game->tilemap.path = malloc(sizeof(int) * 10);
    while (i < 7) {
        game->tilemap.path[i] = path[i];
        i++;
    }
}