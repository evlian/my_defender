/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_enemies
*/
#include "../../include/defender.h"

void display_health_bar(game_instance *game, enemy *enemy)
{
    sfVector2f enemy_pos = enemy->position;
    sfColor color;
    int size = 23 * ((float) enemy->health / enemy->max_health);

    if (enemy->health == enemy->max_health || enemy->health <= 0)
        return;
    if (enemy->health < (enemy->max_health * 0.3))
        color = new_color(255, 0, 0, 255);
    else if (enemy->health < (enemy->max_health * 0.7))
        color = new_color(255, 111, 0, 255);
    else
        color = new_color(48, 255, 25, 255);
    sfRectangleShape_setFillColor(game->shapes.health_bar, color);
    enemy_pos.x += 5;
    sfRectangleShape_setPosition(game->shapes.health_bar, enemy_pos);
    sfRectangleShape_setSize(game->shapes.health_bar, new_vector_2f(size, 4));
    sfRenderWindow_drawRectangleShape(game->window, game->shapes.health_bar, NULL);
}

void display_enemies(game_instance *game)
{
    enemy *head = game->enemies;

    while (head != NULL) {
        sfSprite_setTextureRect(game->sprites.enemy, head->texture_rect);
        sfSprite_setPosition(game->sprites.enemy, head->position);
        sfRenderWindow_drawSprite(game->window, game->sprites.enemy, NULL);
        display_health_bar(game, head);
        head = head->next;
    }
}