/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_menu
*/
#include "../../include/defender.h"

void display_menu(game_instance *game)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rectangle, new_color(0, 0, 0, 200));
    sfRectangleShape_setPosition(rectangle, new_vector_2f(0, 0));
    sfRectangleShape_setSize(rectangle, new_vector_2f(W_WIDTH, W_HEIGHT));
    sfRenderWindow_drawRectangleShape(game->window, rectangle, NULL);
    game->buttons.resume.position = new_vector_2f(W_WIDTH / 2 - 85, 85);
    game->buttons.restart.position = new_vector_2f((W_WIDTH / 2) - 85, 150);
    game->buttons.main_menu.position = new_vector_2f(W_WIDTH / 2 - 85, 215);
    game->buttons.scores.position = new_vector_2f(W_WIDTH / 2 - 85, 280);
    game->buttons.instructions.position = new_vector_2f(W_WIDTH / 2 - 85, 345);
    game->buttons.quit.position = new_vector_2f(W_WIDTH / 2 - 85, 410);
    display_button(game, &game->buttons.main_menu);
    display_button(game, &game->buttons.resume);
    display_button(game, &game->buttons.restart);
    display_button(game, &game->buttons.scores);
    display_button(game, &game->buttons.instructions);
    display_button(game, &game->buttons.quit);
}