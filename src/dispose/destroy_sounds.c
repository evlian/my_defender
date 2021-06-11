/*
** EPITECH PROJECT, 2021
** defender
** File description:
** destroy_sounds
*/
#include "../../include/defender.h"

void destroy_sound_buffers(game_instance *game)
{
    sfSoundBuffer_destroy(game->sound_buffers.archer);
    sfSoundBuffer_destroy(game->sound_buffers.mortar);
    sfSoundBuffer_destroy(game->sound_buffers.click);
    sfSoundBuffer_destroy(game->sound_buffers.hover);
    sfSoundBuffer_destroy(game->sound_buffers.enemy_dies);
    sfSoundBuffer_destroy(game->sound_buffers.game_music);
    sfSoundBuffer_destroy(game->sound_buffers.intro_music);
    sfSoundBuffer_destroy(game->sound_buffers.pause);
}

void destroy_sounds(game_instance *game)
{
    destroy_sound_buffers(game);
    sfSound_destroy(game->sounds.archer);
    sfSound_destroy(game->sounds.mortar);
    sfSound_destroy(game->sounds.click);
    sfSound_destroy(game->sounds.hover);
    sfSound_destroy(game->sounds.enemy_dies);
    sfSound_destroy(game->sounds.game_music);
    sfSound_destroy(game->sounds.intro_music);
    sfSound_destroy(game->sounds.pause);
}