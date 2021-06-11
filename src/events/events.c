/*
** EPITECH PROJECT, 2021
** defender
** File description:
** events
*/
#include "../../include/defender.h"

void manage_exit_event(game_instance *game)
{
    if (game->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyQ)) {
        dispose(game);
    }
}

void manage_events(game_instance *game)
{
    while (sfRenderWindow_pollEvent(game->window, &(game->event))) {
        switch (game->state) {
        case ST_INTRO:
            manage_intro_events(game);
            break;
        case ST_INGAME:
            manage_in_game_events(game);
            break;
        case ST_PAUSE:
            manage_menu_events(game);
            break;
        case ST_GAMEOVER:
            manage_game_over_events(game);
            break;
        default:
            break;
        }
        manage_exit_event(game);
    }
}