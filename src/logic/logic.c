/*
** EPITECH PROJECT, 2021
** defender
** File description:
** logic
*/
#include "../../include/defender.h"

void handle_logic(game_instance *game)
{
    if (game->state != ST_INGAME)
        return;
    move_enemies(game);
    if (game->bullets != NULL)
        hit_target(game);
    move_bullets(game);
    remove_dead_enemies(game);
    attack_enemies(game);
    spawn_enemies(game);
}