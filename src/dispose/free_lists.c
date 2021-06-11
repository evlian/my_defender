/*
** EPITECH PROJECT, 2021
** defender
** File description:
** free_lists
*/
#include "../../include/defender.h"

void free_enemies(game_instance *game)
{
    while (game->enemies != NULL) {
        free(game->enemies);
        game->enemies = game->enemies->next;
    }
}

void free_towers(game_instance *game)
{
    while (game->towers != NULL) {
        free(game->towers);
        game->towers = game->towers->next;
    }
}

void free_bullets(game_instance *game)
{
    while (game->bullets != NULL) {
        free(game->bullets);
        game->bullets = game->bullets->next;
    }
}

void free_lists(game_instance *game)
{
    free_bullets(game);
    free_enemies(game);
    free_towers(game);
}