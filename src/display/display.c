/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display
*/
#include "../../include/defender.h"

void display_build_mode(game_instance *game)
{
    if (!game->build_mode)
        return;
    display_tower_radius(game);
}

void display_in_game(game_instance *game)
{
    display_tilemap(game);
    display_towers(game);
    display_enemies(game);
    display_bullets(game);
    display_build_mode(game);
    display_money(game);
    display_level(game);
    if (sfSprite_getColor(game->sprites.intro).a > 5) {
        sfSprite_setColor(game->sprites.intro, new_color(255, 255, 255,
                            sfSprite_getColor(game->sprites.intro).a - 10));
        sfRenderWindow_drawSprite(game->window, game->sprites.intro, NULL);
    }
    if (game->state == ST_PAUSE)
        display_menu(game);
}

void display(game_instance *game)
{
    switch(game->state) {
        case ST_INTRO:
            display_intro(game);
            break;
        case ST_INGAME: case ST_PAUSE:
            display_in_game(game);
            break;
        case ST_GAMEOVER:
            display_game_over(game);
            break;
    }
    display_instructions(game);
    display_scoreboard(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
}