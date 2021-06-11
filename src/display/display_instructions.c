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
}

void display_instructions(game_instance *game)
{
    if (!game->show_instructions)
        return;

    sfText_setString(game->text, game->instructions);
    sfText_setCharacterSize(game->text, 16);
    sfText_setPosition(game->text, new_vector_2f(WINDOW_WIDTH / 2 - 400, WINDOW_HEIGHT / 2 - 150));
    sfRenderWindow_drawRectangleShape(game->window, game->shapes.panel, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}