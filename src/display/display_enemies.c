/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_enemies
*/
#include "../../include/defender.h"

sfColor get_hp_color(float health, float max_health)
{
    float x = ((float) health / max_health);
    sfColor color = new_color(0, 0, 0, 255);

    if (health > (max_health / 2)) {
        color.r = 255.0 - (255.0 * x);
        color.g = 255.0;
    } else {
        color.g = (255.0 * x);
        color.r = 255.0;
    }
    return color;
}

void display_health_bar(game_instance *game, enemy *enemy)
{
    sfVector2f enemy_pos = enemy->position;
    sfColor color;
    int size = 23 * ((float) enemy->health / enemy->max_health);

    if (enemy->health == enemy->max_health || enemy->health <= 0)
        return;
    color = get_hp_color(enemy->health, enemy->max_health);
    sfRectangleShape_setFillColor(game->shapes.hp_bar, color);
    enemy_pos.x += 5;
    sfRectangleShape_setPosition(game->shapes.hp_bar, enemy_pos);
    sfRectangleShape_setPosition(game->shapes.hp_bar_outline, enemy_pos);
    sfRectangleShape_setSize(game->shapes.hp_bar, new_vector_2f(size, 4));
    sfRenderWindow_drawRectangleShape(game->window,
                                    game->shapes.hp_bar_outline, NULL);
    sfRenderWindow_drawRectangleShape(game->window, game->shapes.hp_bar, NULL);
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