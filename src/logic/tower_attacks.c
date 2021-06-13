/*
** EPITECH PROJECT, 2021
** defender
** File description:
** tower_attacks
*/
#include "../../include/defender.h"

void manage_shooter_attack(game_instance *game, float time, enemy *e,
                            tower *t, sfSound *s)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(t->attack_clock)) > time) {
        e->health -= t->attack;
        sfClock_restart(t->attack_clock);
        shoot_bullet(game, t, e);
        sfSound_play(s);
    }
}

enemy *get_first_enemy(game_instance *game, tower *tower)
{
    enemy *t = NULL;
    enemy *enemy = game->enemies;

    while (enemy != NULL) {
        if (in_circle(tower->position, tower->radius, enemy->position))
            t = enemy;
        enemy = enemy->next;
    }
    return t;
}

void hit_targets(game_instance *game, tower *tower)
{
    enemy *t = get_first_enemy(game, tower);

    if (t == NULL)
        return;
    switch (tower->attack_type) {
        case ATK_LASER:
            t->health -= tower->attack;
            break;
        case ATK_MORTAR:
            manage_shooter_attack(game, 0.3, t, tower, game->sounds.mortar);
            break;
        case ATK_ARROW:
            manage_shooter_attack(game, 0.2, t, tower, game->sounds.archer);
            break;
        default:
            break;
    }
}

void attack_enemies(game_instance *game)
{
    tower *tower = game->towers;

    while (tower != NULL) {
        hit_targets(game, tower);
        tower = tower->next;
    }
}