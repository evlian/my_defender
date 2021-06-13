/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** main file for my defender
*/
#include "../include/defender.h"

int main_loop(game_instance *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        manage_events(game);
        handle_logic(game);
        display(game);
    }
    return 0;
}

int main(int argc, char **argv)
{
    game_instance game;

    init(&game);
    return main_loop(&game);
}