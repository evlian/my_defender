/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** dispose
*/
#include "../../include/defender.h"

void dispose(game_instance *game)
{
    sfRenderWindow_close(game->window);
    destroy_textures(game);
    destroy_sounds(game);
    free_lists(game);
}