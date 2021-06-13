/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init_scores
*/
#include "../../include/defender.h"

void load_scores(game_instance *game)
{
    game->scores = csv_to_array("./res/scores.csv")[0];
    sort(game->scores, array_len(game->scores), 0);
}

void init_scoreboard_panel(game_instance *game)
{
    game->shapes.scores_panel = sfRectangleShape_create();
    sfRectangleShape_setSize(game->shapes.scores_panel,
                            new_vector_2f(500, 360));
    sfRectangleShape_setPosition(game->shapes.scores_panel,
                                new_vector_2f(W_WIDTH / 2 - 250,
                                            W_HEIGHT / 2 - 150));
    sfRectangleShape_setFillColor(game->shapes.scores_panel,
                                new_color(60, 141, 173, 225));
    sfRectangleShape_setScale(game->shapes.scores_panel,
                            new_vector_2f(0.2, 0.2));
}

void init_scoreboard(game_instance *game)
{
    load_scores(game);
    init_scoreboard_panel(game);
}
