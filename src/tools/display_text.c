/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_text
*/
#include "../../include/defender.h"

void display_text(game_instance *game, char const *string)
{
    sfText_setString(game->text, string);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}

void display_number(game_instance *game, int nbr)
{
    char *number = malloc(sizeof(int) * my_num_len(nbr));

    int_to_string(number, nbr);
    display_text(game, number);
    free(number);
}