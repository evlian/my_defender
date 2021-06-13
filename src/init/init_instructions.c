/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_instructions
*/
#include "../../include/defender.h"

void init_panel(game_instance *game)
{
    game->shapes.info_panel = sfRectangleShape_create();
    sfRectangleShape_setSize(game->shapes.info_panel, new_vector_2f(800, 320));
    sfRectangleShape_setPosition(game->shapes.info_panel,
                                new_vector_2f(W_WIDTH / 2 - 400,
                                            W_HEIGHT / 2 - 150));
    sfRectangleShape_setFillColor(game->shapes.info_panel,
                                new_color(60, 141, 173, 225));
    sfRectangleShape_setScale(game->shapes.info_panel,
                                new_vector_2f(0.2, 0.2));
}

void init_instructions(game_instance *game)
{
    game->instructions = read_file("./res/instructions.txt");
    game->buttons.instructions.on_click = &display_instructions;
    init_panel(game);
}