/*
** EPITECH PROJECT, 2021
** defender
** File description:
** initialiser
*/
#include "../../include/defender.h"

void init_window(game_instance *game)
{
    game->window = sfRenderWindow_create(
        new_video_mode(W_WIDTH, W_HEIGHT, BITS_PER_PIXEL),
        GAME_TITLE, sfTitlebar | sfClose , NULL);
    sfRenderWindow_setFramerateLimit(game->window, FRAME_RATE);
    game->icon = sfImage_createFromFile("./res/icon.png");
    sfRenderWindow_setIcon(game->window, 512, 512,
                            sfImage_getPixelsPtr(game->icon));
}

void set_settings(game_instance *game)
{
    game->build_mode = sfFalse;
    game->show_instructions = sfFalse;
    game->show_scores = sfFalse;
    game->enemy_wave = 5;
    game->enemy_health = 1000;
    game->money = 500;
    game->amount_of_enemies = game->enemy_wave;
}

void init(game_instance *game)
{
    srand((unsigned long)&game);
    game->score = 0;
    game->state = ST_INTRO;
    set_settings(game);
    init_scoreboard(game);
    init_window(game);
    init_sounds(game);
    init_instructions(game);
    init_intro(game);
    init_ui(game);
    init_path(game);
    init_tilemap(game);
    init_towers(game);
    init_money(game);
    init_text(game);
    init_enemies(game);
    init_bullets(game);
    init_game_over(game);
    sfSound_play(game->sounds.intro_music);
}