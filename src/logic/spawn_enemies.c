/*
** EPITECH PROJECT, 2021
** defender
** File description:
** spawn_enemies
*/
#include "../../include/defender.h"

void increase_spawn_health(game_instance *game, float m)
{
    enemy *head = game->enemy_types;

    while (head != NULL) {
        head->max_health *= m;
        head = head->next;
    }
}

void spawn_enemies(game_instance *game)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->spawn_clock)) < 0.5)
        return;
    sfClock_restart(game->spawn_clock);
    if (game->enemies == NULL) {
        game->enemy_wave *= 1.2;
        game->amount_of_enemies = game->enemy_wave;
       increase_spawn_health(game, 1.2);
    }
    if (game->amount_of_enemies > 0) {
        game->amount_of_enemies--;
        add_enemy(game);
    }
}