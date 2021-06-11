/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_towers
*/
#include "../../include/defender.h"

void init_tower_radius(game_instance *game)
{
    game->shapes.radius = sfCircleShape_create();
    sfCircleShape_setFillColor(game->shapes.radius, new_color(205, 205, 205, 60));
    game->shapes.winter = sfCircleShape_create();
    sfCircleShape_setFillColor(game->shapes.winter, new_color(123, 165, 248, 100));
}

void init_tower_bar(game_instance *game)
{
    game->shapes.tower_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->shapes.tower_bar, new_color(51, 170, 255, 150));
    sfRectangleShape_setPosition(game->shapes.tower_bar, new_vector_2f(WINDOW_WIDTH / 2 - 160, WINDOW_HEIGHT - 64));
    sfRectangleShape_setSize(game->shapes.tower_bar, new_vector_2f(320, 64));
    game->shapes.tower_highlighter = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->shapes.tower_highlighter, new_color(60, 60, 60, 100));
    sfRectangleShape_setSize(game->shapes.tower_highlighter, new_vector_2f(80, 64));
}

void init_towers(game_instance *game)
{
    game->sprites.tower = sfSprite_create();
    sfSprite_setTexture(game->sprites.tower, game->tileset.tileset, sfTrue);
    init_tower_radius(game);
    game->towers = NULL;
    game->selected_tower = NULL;
    game->tower_choices = NULL;
    add_tower_choice(game, new_int_rect(32, 32, 22 * 32, 7 * 32), 5,
                    100, ATK_LASER, 550, "Laser", new_color(255, 90, 90, 255));
    add_tower_choice(game, new_int_rect(32, 32, 21 * 32, 7 * 32), 80,
                    250, ATK_ARROW, 400, "Archer", new_color(227, 107, 174, 255));
    add_tower_choice(game, new_int_rect(32, 32, 20 * 32, 7 * 32), 2,
                    140, ATK_SLOW_DOWN, 300, "Winter", new_color(62, 219, 240, 255));
    add_tower_choice(game, new_int_rect(32, 32, 19 * 32, 7 * 32), 250,
                    90, ATK_MORTAR, 250, "Mortar", new_color(80, 80, 80, 255));
    game->selected_tower = game->tower_choices->next->next->next;
    game->highlighted_tower = -1;
    init_tower_bar(game);
}