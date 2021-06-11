/*
** EPITECH PROJECT, 2021
** defender
** File description:
** intro_events
*/
#include "../../include/defender.h"

void manage_intro_events(game_instance *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (game->event.type == sfEvtMouseMoved) {
        manage_button_hover(game, mouse, game->main_menu_buttons);
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        manage_button_click(game, game->main_menu_buttons);
    }
}