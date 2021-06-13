/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_scoreboard
*/
#include "../../include/defender.h"

void toggle_scoreboard(game_instance *game)
{
    game->show_scores = !game->show_scores;
    if (game->show_scores) {
        sfRectangleShape_setScale(game->shapes.info_panel,
                                    new_vector_2f(0.2, 0.2));
        game->show_instructions = sfFalse;
    } else {
        sfRectangleShape_setPosition(game->shapes.scores_panel,
                                    game->buttons.scores.position);
        sfRectangleShape_setScale(game->shapes.scores_panel,
                                    new_vector_2f(0.2, 0.2));
    }
}

void display_scores(game_instance *game, sfVector2f pos)
{
    int i = 0;

    while (i < 10) {
        sfText_setCharacterSize(game->text, 18);
        sfText_setPosition(game->text, pos);
        display_number(game, i + 1);
        sfText_setCharacterSize(game->text, 18);
        pos.x = sfText_getGlobalBounds(game->text).left +
                                sfText_getGlobalBounds(game->text).width + 5;
        sfText_setPosition(game->text, pos);
        display_text(game, ".");
        pos.x = sfText_getGlobalBounds(game->text).left +
                                sfText_getGlobalBounds(game->text).width + 10;
        sfText_setPosition(game->text, pos);
        display_number(game, game->scores[i]);
        pos.x = W_WIDTH / 2 - 250 + 5;
        pos.y += 30;
        i++;
    }
}

void display_scoreboard(game_instance *game)
{
    char *s;
    sfVector2f pos = sfRectangleShape_getPosition(game->shapes.scores_panel);

    pos = new_vector_2f(pos.x + 5, pos.y);
    if (!game->show_scores)
        return;
    if (sfRectangleShape_getScale(game->shapes.scores_panel).x < 1) {
        animate_panel(game, game->shapes.scores_panel);
        sfRenderWindow_drawRectangleShape(game->window,
                                        game->shapes.scores_panel, NULL);
        return;
    }
    sfRenderWindow_drawRectangleShape(game->window,
                                    game->shapes.scores_panel, NULL);
    sfText_setString(game->text, "SCOREBOARD");
    sfText_setCharacterSize(game->text, 36);
    sfText_setPosition(game->text, pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    display_scores(game, new_vector_2f(pos.x, pos.y + 50));
}