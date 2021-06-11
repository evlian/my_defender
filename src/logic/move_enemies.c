/*
** EPITECH PROJECT, 2021
** defender
** File description:
** move_enemies
*/
#include "../../include/defender.h"

void animate_enemy(enemy *enemy)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy->clock)) < 0.2)
        return;
    sfClock_restart(enemy->clock);
    if (enemy->texture_rect.left == (96 - 32)) {
        enemy->texture_rect.left = 0;
    } else {
        enemy->texture_rect.left += 32;
    }
}

int is_path_tile(game_instance *game, sfVector2i tile)
{
    return game->tilemap.layer1[tile.y][tile.x].is_path;
}

int is_dead_end(game_instance *game, int direction, sfVector2f position)
{
    position.x /= game->tileset.tile_size;
    position.y /= game->tileset.tile_size;
    switch (direction) {
        case DIR_UP:
            return !is_path_tile(game, new_vector_2i(position.x, position.y - 1));
        case DIR_RIGHT:
            return !is_path_tile(game, new_vector_2i(position.x + 1, position.y));
        case DIR_DOWN:
            return !is_path_tile(game, new_vector_2i(position.x, position.y + 1));
        default:
            return 0;
    }
}

float check_slow_attack(game_instance *game, enemy *enemy)
{
    tower *head = game->towers;
    float attack = 0.0;

    while (head != NULL) {
        if (head->attack_type == ATK_SLOW_DOWN &&
            in_circle(head->position, head->radius, enemy->position)) {
            attack += head->attack;
        }
        head = head->next;
    }
    return attack == 0.0 ? 1.0 : attack;
}

void move_enemies(game_instance *game)
{
    enemy *head = game->enemies;
    int dir;
    float speed;

    while (head != NULL) {
        if (is_game_over(game, head->position)) {
            reset_game(game);
            game->state = ST_GAMEOVER;
            return;
        }
        animate_enemy(head);
        dir = head->direction;
        speed = (float) head->speed / check_slow_attack(game, head);
        head->texture_rect.top = head->direction * 32;
        if (is_dead_end(game, head->direction, head->position)) {
            dir = game->tilemap.path[head->path_index++];
            head->direction = dir;
        }
        if (dir == DIR_UP)
            head->position.y -= speed;
        else if (dir == DIR_RIGHT)
            head->position.x += speed;
        else if (dir == DIR_DOWN)
            head->position.y += speed;
        head = head->next;
    }
}