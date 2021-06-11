/*
** EPITECH PROJECT, 2021
** defender
** File description:
** tower_attacks
*/
#include "../../include/defender.h"

int in_circle(sfVector2f center, int radius, sfVector2f target)
{
    float square_dist = pow((center.x - target.x), 2)
                        + pow((center.y - target.y), 2);
    return square_dist <= pow(radius, 2);
}

int get_dist(sfVector2f center, sfVector2f target)
{
    return pow((center.x - target.x), 2) + pow((center.y - target.y), 2);
}

void hit_targets(game_instance *game, tower *tower)
{
    enemy *t = NULL;
    enemy *enemy = game->enemies;

    while (enemy != NULL) {
        if (in_circle(tower->position, tower->radius, enemy->position)) {
            t = enemy;
        }
        enemy = enemy->next;
    }
    if (t != NULL)
        switch (tower->attack_type) {
            case ATK_LASER:
                t->health -= tower->attack;
                break;
            case ATK_MORTAR:
                if (sfTime_asSeconds(sfClock_getElapsedTime(tower->attack_clock)) > 0.3) {
                    t->health -= tower->attack;
                    sfClock_restart(tower->attack_clock);
                    shoot_bullet(game, tower, t);
                    sfSound_play(game->sounds.mortar);
                }
                break;
            case ATK_ARROW:
                if (sfTime_asSeconds(sfClock_getElapsedTime(tower->attack_clock)) > 0.2) {
                    t->health -= tower->attack;
                    sfClock_restart(tower->attack_clock);
                    shoot_bullet(game, tower, t);
                    sfSound_play(game->sounds.archer);
                }
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