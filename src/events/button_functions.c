/*
** EPITECH PROJECT, 2021
** defender
** File description:
** button_functions
*/
#include "../../include/defender.h"

void play_button(game_instance *game)
{
    game->score = 0;
    game->state = ST_INGAME;
    game->show_instructions = sfFalse;
    game->show_scores = sfFalse;
    play_music(game);
}

void resume_button(game_instance *game)
{
    game->state = ST_INGAME;
    game->show_instructions = sfFalse;
    game->show_scores = sfFalse;
    sfSound_play(game->sounds.pause);
    sfSound_play(game->sounds.game_music);
}

void restart_button(game_instance *game)
{
    reset_game(game);
    game->score = 0;
    game->state = ST_INGAME;
    game->show_instructions = sfFalse;
    game->show_scores = sfFalse;
    play_music(game);
}

void main_menu_button(game_instance *game)
{
    reset_game(game);
    game->score = 0;
    game->state = ST_INTRO;
    game->show_instructions = sfFalse;
    game->show_scores = sfFalse;
    play_music(game);
}