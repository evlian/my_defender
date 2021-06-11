/*
** EPITECH PROJECT, 2021
** defender
** File description:
** sounds
*/
#include "../../include/defender.h"

void play_music(game_instance *game)
{
    switch (game->state) {
        case ST_INTRO:
            sfSound_stop(game->sounds.game_music);
            sfSound_play(game->sounds.intro_music);
            break;
        case ST_INGAME:
            sfSound_stop(game->sounds.intro_music);
            sfSound_play(game->sounds.game_music);
            break;
    }
}