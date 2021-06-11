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
}

void display_scoreboard(game_instance *game)
{
    int i = 0;
    char *s;
    sfVector2f pos = sfRectangleShape_getPosition(game->shapes.scoreboard_panel);

    pos.x += 5;
    if (!game->show_scores)
        return;
    sfRenderWindow_drawRectangleShape(game->window, game->shapes.scoreboard_panel, NULL);
    sfText_setString(game->text, "SCOREBOARD");
    sfText_setCharacterSize(game->text, 36);
    sfText_setPosition(game->text, pos);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    pos.y += 50;
    while (i < 10) {
        sfText_setCharacterSize(game->text, 18);
        sfText_setPosition(game->text, pos);
        display_number(game, i + 1);
        sfText_setCharacterSize(game->text, 18);
        pos.x = sfText_getGlobalBounds(game->text).left + sfText_getGlobalBounds(game->text).width + 5;
        sfText_setPosition(game->text, pos);
        display_text(game, ".");
        pos.x = sfText_getGlobalBounds(game->text).left + sfText_getGlobalBounds(game->text).width + 10;
        sfText_setPosition(game->text, pos);
        display_number(game, game->scores[i]);
        pos.x = WINDOW_WIDTH / 2 - 250 + 5;
        pos.y += 30;
        i++;
    }
}