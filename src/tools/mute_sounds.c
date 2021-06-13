/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** mute_sounds
*/
#include "../../include/defender.h"

void mute_sounds(game_instance *game, char *flag, int argc)
{
    if (argc > 1 && my_strcmp("-m", flag) == 0) {
        sfSound_setVolume(game->sounds.intro_music, 0);
        sfSound_setVolume(game->sounds.game_music, 0);
        sfSound_setVolume(game->sounds.archer, 0);
        sfSound_setVolume(game->sounds.mortar, 0);
        sfSound_setVolume(game->sounds.enemy_dies, 0);
        sfSound_setVolume(game->sounds.tower_placed, 0);
    }
}