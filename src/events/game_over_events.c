/*
** EPITECH PROJECT, 2021
** defender
** File description:
** game_over_events
*/
#include "../../include/defender.h"

void manage_game_over_events(game_instance *game)
{
    if (game->event.type == sfEvtKeyPressed) {
        switch (game->event.key.code) {
        case sfKeyR:
            game->state = ST_INGAME;
            game->score = 0;
            sfSound_stop(game->sounds.intro_music);
            sfSound_play(game->sounds.game_music);
            break;
        case sfKeyM:
            game->state = ST_INTRO;
            game->score = 0;
            break;
        default:
            break;
        }
    }
}