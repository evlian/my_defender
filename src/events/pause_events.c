/*
** EPITECH PROJECT, 2021
** defender
** File description:
** pause_event
*/
#include "../../include/defender.h"

void manage_pause_event(game_instance *game)
{
    int escape = game->event.key.code == sfKeyEscape;

    if (game->event.type != sfEvtKeyPressed)
        return;

    if (game->state == ST_INGAME && escape) {
        sfSound_play(game->sounds.pause);
        sfSound_pause(game->sounds.game_music);
        game->state = ST_PAUSE;
    } else if (game->state == ST_PAUSE && escape) {
        sfSound_play(game->sounds.pause);
        sfSound_play(game->sounds.game_music);
        game->show_instructions = sfFalse;
        game->show_scores = sfFalse;
        game->state = ST_INGAME;
    }
}

void manage_pause_events(game_instance *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (game->event.type == sfEvtMouseMoved) {
        manage_button_hover(game, mouse, game->pause_menu_buttons);
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        manage_button_click(game, game->pause_menu_buttons);
    }
}