/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_towers
*/
#include "../../include/defender.h"

void draw_highlighted_tower(game_instance *game)
{
    sfVector2f pos = new_vector_2f(WINDOW_WIDTH / 2 - 160, WINDOW_HEIGHT - 64);
    int i = 0;

    if (game->highlighted_tower == -1)
        return;
    while (i < 4) {
        if (i == game->highlighted_tower) {
            sfRectangleShape_setPosition(game->shapes.tower_highlighter, pos);
            game->highlighted_tower = i;
            break;
        }
        pos.x += 80;
        i++;
    }
    sfRenderWindow_drawRectangleShape(game->window, game->shapes.tower_highlighter, NULL);
}

void display_tower_choices(game_instance *game)
{
    tower *t = game->tower_choices;
    sfVector2f tower_pos = new_vector_2f(WINDOW_HEIGHT / 2 + 87, WINDOW_HEIGHT - 64);
    sfVector2f price_pos = new_vector_2f(tower_pos.x + 2, tower_pos.y + 47);
    sfVector2f name_pos = new_vector_2f(tower_pos.x - 5, tower_pos.y + 37);

    while (t != NULL) {
        sfText_setColor(game->text, sfYellow);
        sfText_setCharacterSize(game->text, 14);
        sfSprite_setTextureRect(game->sprites.tower, t->texture);
        sfSprite_setPosition(game->sprites.tower, tower_pos);
        sfSprite_setColor(game->sprites.tower, t->color);
        sfText_setPosition(game->text, price_pos);
        display_number(game, t->price);
        sfRenderWindow_drawSprite(game->window, game->sprites.tower, NULL);
        sfText_setColor(game->text, sfRed);
        if (game->money >= t->price)
            sfText_setColor(game->text, sfGreen);
        sfText_setCharacterSize(game->text, 10);
        sfText_setPosition(game->text, name_pos);
        sfText_setString(game->text, t->name);
        sfRenderWindow_drawText(game->window, game->text, NULL);
        tower_pos.x += 80;
        price_pos.x += 80;
        name_pos.x += 80;
        t = t->next;
    }
}

void display_tower_bar(game_instance *game)
{
    sfRenderWindow_drawRectangleShape(game->window, game->shapes.tower_bar, NULL);
    display_tower_choices(game);
    draw_highlighted_tower(game);
}

void display_laser(game_instance *game, tower *tower)
{
    enemy *head = game->enemies;

    while (head != NULL) {
        if (in_circle(tower->position, tower->radius, head->position)) {
            game->shapes.point_one.position = tower->position;
            game->shapes.point_two.position = head->position;
            game->shapes.point_one.position.x += 20;
            game->shapes.point_one.position.y += 20;
            game->shapes.point_two.position.x += 20;
            game->shapes.point_two.position.y += 20;
            sfVertexArray_clear(game->shapes.line);
            sfVertexArray_append(game->shapes.line, game->shapes.point_one);
            sfVertexArray_append(game->shapes.line, game->shapes.point_two);
            sfRenderWindow_drawVertexArray(game->window, game->shapes.line, NULL);
        }
        head = head->next;
    }
}

void display_cold_circle(game_instance *game, tower *tower)
{
    enemy *head = game->enemies;
    sfVector2f pos = tower->position;

    pos.x -= (tower->radius - 16);
    pos.y -= (tower->radius - 16);
    while (head != NULL) {
        if (in_circle(tower->position, tower->radius, head->position)) {
            sfCircleShape_setRadius(game->shapes.winter, tower->radius);
            sfCircleShape_setPosition(game->shapes.winter, pos);
            sfRenderWindow_drawCircleShape(game->window, game->shapes.winter, NULL);
            break;
        }
        head = head->next;
    }
}

void display_towers(game_instance *game)
{
    tower *head = game->towers;

    display_tower_bar(game);
    while (head != NULL) {
        if (head->attack_type == ATK_LASER)
            display_laser(game, head);
        else if (head->attack_type == ATK_SLOW_DOWN)
            display_cold_circle(game, head);
        sfSprite_setTextureRect(game->sprites.tower, head->texture);
        sfSprite_setPosition(game->sprites.tower, head->position);
        sfSprite_setColor(game->sprites.tower, head->color);
        sfRenderWindow_drawSprite(game->window, game->sprites.tower, NULL);
        sfSprite_setColor(game->sprites.tower, sfWhite);
        head = head->next;
    }
}