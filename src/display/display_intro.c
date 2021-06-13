/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_intro
*/
#include "../../include/defender.h"

void display_intro_buttons(game_instance *game)
{
    game->buttons.play.position = new_vector_2f(30, 250);
    display_button(game, &game->buttons.play);
    game->buttons.scores.position = new_vector_2f(30, 310);
    display_button(game, &game->buttons.scores);
    game->buttons.instructions.position = new_vector_2f(30, 370);
    display_button(game, &game->buttons.instructions);
    game->buttons.quit.position = new_vector_2f(30, 430);
    display_button(game, &game->buttons.quit);
}

void animate_intro(game_instance *game)
{
    sfFloatRect bounds;
    float w;
    float h;
    sfVector2f pos;

    sfSprite_scale(game->sprites.intro, new_vector_2f(1.1, 1.1));
    bounds = sfSprite_getGlobalBounds(game->sprites.intro);
    w = W_WIDTH / 2.0 - bounds.width / 2.0;
    h = W_HEIGHT / 2.0 - bounds.height / 2.0;
    pos = new_vector_2f(w, h);
    sfSprite_setPosition(game->sprites.intro, pos);
}

void display_intro(game_instance *game)
{
    sfVector2f pos = sfSprite_getPosition(game->sprites.intro);

    sfSprite_setColor(game->sprites.intro, sfWhite);
    if (sfSprite_getScale(game->sprites.intro).x < 1) {
        animate_intro(game);
        sfRenderWindow_drawSprite(game->window, game->sprites.intro, NULL);
    } else {
        sfRenderWindow_drawSprite(game->window, game->sprites.intro, NULL);
        display_intro_buttons(game);
    }
}