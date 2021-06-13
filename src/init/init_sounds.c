/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_sounds
*/
#include "../../include/defender.h"

void set_sound_settings(game_instance *game)
{
    sfSound_setLoop(game->sounds.game_music, sfTrue);
    sfSound_setLoop(game->sounds.intro_music, sfTrue);
    sfSound_setVolume(game->sounds.intro_music, 60);
    sfSound_setVolume(game->sounds.game_music, 20);
}

void create_sounds(game_instance *game)
{
    game->sounds.hover = sfSound_create();
    game->sounds.click = sfSound_create();
    game->sounds.enemy_dies = sfSound_create();
    game->sounds.game_music = sfSound_create();
    game->sounds.intro_music = sfSound_create();
    game->sounds.pause = sfSound_create();
    game->sounds.tower_placed = sfSound_create();
    game->sounds.archer = sfSound_create();
    game->sounds.mortar = sfSound_create();
}

void init_sound_buffers(game_instance *game)
{
    game->sound_buffers.hover =
        sfSoundBuffer_createFromFile("./res/hover.ogg");
    game->sound_buffers.click =
        sfSoundBuffer_createFromFile("./res/click.ogg");
    game->sound_buffers.enemy_dies =
        sfSoundBuffer_createFromFile("./res/death.wav");
    game->sound_buffers.game_music =
        sfSoundBuffer_createFromFile("./res/gameplay.ogg");
    game->sound_buffers.intro_music =
        sfSoundBuffer_createFromFile("./res/intro.ogg");
    game->sound_buffers.pause =
        sfSoundBuffer_createFromFile("./res/pause.ogg");
    game->sound_buffers.tower_placed =
        sfSoundBuffer_createFromFile("./res/tower_placed.ogg");
    game->sound_buffers.archer =
        sfSoundBuffer_createFromFile("./res/archer.ogg");
    game->sound_buffers.mortar =
        sfSoundBuffer_createFromFile("./res/mortar.ogg");
}

void set_sound_buffers(game_instance *game)
{
    sfSound_setBuffer(game->sounds.hover, game->sound_buffers.hover);
    sfSound_setBuffer(game->sounds.click, game->sound_buffers.click);
    sfSound_setBuffer(game->sounds.enemy_dies, game->sound_buffers.enemy_dies);
    sfSound_setBuffer(game->sounds.game_music, game->sound_buffers.game_music);
    sfSound_setBuffer(game->sounds.intro_music, game->sound_buffers.intro_music);
    sfSound_setBuffer(game->sounds.pause, game->sound_buffers.pause);
    sfSound_setBuffer(game->sounds.tower_placed,
                    game->sound_buffers.tower_placed);
    sfSound_setBuffer(game->sounds.archer, game->sound_buffers.archer);
    sfSound_setBuffer(game->sounds.mortar, game->sound_buffers.mortar);
}

void init_sounds(game_instance *game)
{
    init_sound_buffers(game);
    create_sounds(game);
    set_sound_buffers(game);
    set_sound_settings(game);
}