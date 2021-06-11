/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_instructions
*/
#include "../../include/defender.h"

void toggle_instructions(game_instance *game)
{
    game->show_instructions = !game->show_instructions;
    if (game->show_instructions) {
        sfRectangleShape_setScale(game->shapes.scoreboard_panel, new_vector_2f(0.2, 0.2));
        game->show_scores = sfFalse;
    }
    else
        sfRectangleShape_setScale(game->shapes.panel, new_vector_2f(0.2, 0.2));
}

void display_instructions(game_instance *game)
{
    if (!game->show_instructions)
        return;

    if (sfRectangleShape_getScale(game->shapes.panel).x < 1) {
        sfRectangleShape_scale(game->shapes.panel, new_vector_2f(1.1, 1.1));
        sfRectangleShape_setPosition(game->shapes.panel, new_vector_2f(WINDOW_WIDTH / 2.0 - sfRectangleShape_getGlobalBounds(game->shapes.panel).width / 2.0,
                                                                WINDOW_HEIGHT / 2.0 - sfRectangleShape_getGlobalBounds(game->shapes.panel).height / 2.0));
        sfRenderWindow_drawRectangleShape(game->window, game->shapes.panel, NULL);
    } else {
        sfText_setString(game->text, game->instructions);
        sfText_setCharacterSize(game->text, 16);
        sfText_setPosition(game->text, new_vector_2f(WINDOW_WIDTH / 2 - 400, WINDOW_HEIGHT / 2 - 150));
        sfRenderWindow_drawRectangleShape(game->window, game->shapes.panel, NULL);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }

}