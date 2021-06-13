/*
** EPITECH PROJECT, 2021
** defender
** File description:
** manage_enemies
*/
#include "../../include/defender.h"

enemy *get_random_type(game_instance *game)
{
    int random = 4 - (rand() % (4) + 1);
    enemy *temp = game->enemy_types;

    while (random-- > 0) {
        temp = temp->next;
    }
    return temp;
}

void add_enemy(game_instance *game)
{
    enemy *new = (enemy *) malloc(sizeof(enemy));
    enemy *type = get_random_type(game);

    new->max_health = type->max_health;
    new->health = new->max_health;
    new->texture_rect = new_int_rect(32, 32, 0, 0);
    new->position = new_vector_2f(1, 64);
    new->next = game->enemies;
    new->speed = type->speed;
    new->type = type->type;
    new->clock = sfClock_create();
    new->path_index = 0;
    new->direction = DIR_RIGHT;
    game->enemies = new;
}

void on_dead_enemy(game_instance *game, enemy *enemy)
{
    sfSound_play(game->sounds.enemy_dies);
    game->score += enemy->max_health / 100;
    game->money += enemy->max_health / 19;
}

void remove_dead_enemies(game_instance *game)
{
    enemy *temp = game->enemies;
    enemy *prev;

    while (temp != NULL && temp->health <= 0) {
        game->enemies = temp->next;
        on_dead_enemy(game, temp);
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
        on_dead_enemy(game, temp);
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}