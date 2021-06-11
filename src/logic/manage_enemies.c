/*
** EPITECH PROJECT, 2021
** defender
** File description:
** manage_enemies
*/
#include "../../include/defender.h"

void add_enemy(game_instance *game)
{
    enemy *new = (enemy *) malloc(sizeof(enemy));

    new->max_health = game->enemy_health;
    new->health = new->max_health;
    new->texture_rect = new_int_rect(32, 32, 0, 0);
    new->position = new_vector_2f(0, 64);
    new->next = game->enemies;
    new->speed = 1;
    new->clock = sfClock_create();
    new->path_index = 0;
    new->direction = DIR_RIGHT;
    game->enemies = new;
}

void remove_dead_enemies(game_instance *game)
{
    enemy *temp = game->enemies;
    enemy *prev;

    while (temp != NULL && temp->health <= 0) {
        game->enemies = temp->next;
        sfSound_play(game->sounds.enemy_dies);
        game->score += temp->max_health / 100;
        game->money += temp->max_health / 22;
        free(temp);
        temp = game->enemies;
    }
    while (temp != NULL) {
        while (temp != NULL && temp->health > 0) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        game->score += temp->max_health / 100;
        game->money += temp->max_health / 68;
        sfSound_play(game->sounds.enemy_dies);
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}