/*
** EPITECH PROJECT, 2021
** defender
** File description:
** game_over
*/
#include "../../include/defender.h"

void reset_game(game_instance *game)
{
    free_enemies(game);
    free_towers(game);
    free_bullets(game);
    set_settings(game);
}

int is_game_over(game_instance *game, sfVector2f pos)
{
    int a = pos.x /= 32;
    int b = pos.y /= 32;

    if (a == 27 && b == 17) {
        save_score(game);
        sfSound_stop(game->sounds.game_music);
        sfSound_play(game->sounds.intro_music);
    }
    return (a == 27 && b == 17);
}