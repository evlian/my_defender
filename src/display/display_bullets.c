/*
** EPITECH PROJECT, 2021
** defender
** File description:
** display_bullets
*/
#include "../../include/defender.h"

void display_bullets(game_instance *game)
{
    bullet *head = game->bullets;

    while (head != NULL) {
        sfSprite_setTextureRect(game->sprites.bullet, head->texture_rect);
        sfSprite_setPosition(game->sprites.bullet, head->position);
        sfRenderWindow_drawSprite(game->window, game->sprites.bullet, NULL);
        head = head->next;
    }
}