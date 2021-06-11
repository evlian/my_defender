/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_instructions
*/
#include "../../include/defender.h"

void init_panel(game_instance *game)
{
    game->shapes.panel = sfRectangleShape_create();
    sfRectangleShape_setSize(game->shapes.panel, new_vector_2f(800, 320));
    sfRectangleShape_setPosition(game->shapes.panel,
                                new_vector_2f(WINDOW_WIDTH / 2 - 400,
                                            WINDOW_HEIGHT / 2 - 150));
    sfRectangleShape_setFillColor(game->shapes.panel, new_color(0x3c, 0x8d, 0xad, 225));
    sfRectangleShape_setScale(game->shapes.panel, new_vector_2f(0.2, 0.2));
}

void init_instructions(game_instance *game)
{
    game->instructions = read_file("./res/instructions.txt");
    game->buttons.instructions.on_click = &display_instructions;
    init_panel(game);
}