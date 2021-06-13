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
        sfRectangleShape_setScale(game->shapes.scores_panel,
                                    new_vector_2f(0.2, 0.2));
        game->show_scores = sfFalse;
    } else {
        sfRectangleShape_setScale(game->shapes.info_panel,
                                    new_vector_2f(0.2, 0.2));
    }
}

void display_instructions(game_instance *game)
{
    sfVector2f pos = new_vector_2f(W_WIDTH / 2 - 400, W_HEIGHT / 2 - 150);

    if (!game->show_instructions)
        return;
    if (sfRectangleShape_getScale(game->shapes.info_panel).x < 1) {
        animate_panel(game, game->shapes.info_panel);
        sfRenderWindow_drawRectangleShape(game->window,
                                            game->shapes.info_panel, NULL);
    } else {
        sfText_setString(game->text, game->instructions);
        sfText_setCharacterSize(game->text, 16);
        sfText_setPosition(game->text, pos);
        sfRenderWindow_drawRectangleShape(game->window,
                                        game->shapes.info_panel, NULL);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
}