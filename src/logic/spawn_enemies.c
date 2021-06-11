/*
** EPITECH PROJECT, 2021
** defender
** File description:
** spawn_enemies
*/
#include "../../include/defender.h"

void spawn_enemies(game_instance *game)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->spawn_clock)) < 0.5)
        return;
    sfClock_restart(game->spawn_clock);
    if (game->enemies == NULL) {
        game->enemy_wave *= 1.2;
        game->amount_of_enemies = game->enemy_wave;
        game->enemy_health *= 1.1;
    }
    if (game->amount_of_enemies > 0) {
        game->amount_of_enemies--;
        add_enemy(game);
    }
}