/*
** EPITECH PROJECT, 2021
** defender
** File description:
** in_game_events
*/
#include "../../include/defender.h"

void set_selected_tile(game_instance *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2i x = game->tilemap.last_selected;

    if (game->event.type == sfEvtMouseMoved && game->build_mode) {
        if (mouse.y < WINDOW_HEIGHT && mouse.x < WINDOW_WIDTH) {
            game->tilemap.layer1[x.y][x.x].is_selected = 0;
            game->tilemap.layer1[mouse.y / 32][mouse.x / 32].is_selected = 1;
            set_vector_2i(&game->tilemap.last_selected,  mouse.y / 32, mouse.x / 32);
            set_vector_2f(&game->selected_tower->position, (mouse.y / 32) * 32, (mouse.x / 32) * 32);
        }
    }
}

void manage_build_tower_event(game_instance *game)
{
    sfVector2i tile = game->tilemap.last_selected;

    if (game->build_mode) {
        if (game->tilemap.layer1[tile.y][tile.x].is_tower_host) {
            add_tower(game, new_vector_2f(tile.x * 32, tile.y * 32));
            sfSound_play(game->sounds.tower_placed);
            game->build_mode = sfFalse;
            game->money -= game->selected_tower->price;
            game->selected_tower->position = new_vector_2f(-1, -1);
        }
    }
}

void select_tower_event(game_instance *game)
{
    sfIntRect rect = vector_to_rect(new_vector_2f(WINDOW_WIDTH / 2 - 160, WINDOW_HEIGHT - 64), 80, 64);
    tower *head = game->tower_choices;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    while (head != NULL) {
        if(sfIntRect_contains(&rect, mouse.x, mouse.y) && game->money >= head->price) {
            game->selected_tower = head;
            game->build_mode = sfTrue;
            return;
        }
        rect.width += 80;
        head = head->next;
    }
}

void hover_tower_selector_event(game_instance *game)
{
    sfIntRect rect = vector_to_rect(new_vector_2f(WINDOW_WIDTH / 2 - 160, WINDOW_HEIGHT - 64), 80, 64);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    int i = 0;

    game->highlighted_tower = -1;
    while (i < 4) {
        if (sfIntRect_contains(&rect, mouse.x, mouse.y)) {
            game->highlighted_tower = i;
            break;
        }
        rect.left += 80;
        i++;
    }
}

void manage_in_game_events(game_instance *game)
{
    set_selected_tile(game);
    if (game->event.type == sfEvtMouseMoved) {
        hover_tower_selector_event(game);
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (game->event.key.code == sfMouseRight) {
            game->build_mode = sfFalse;
        }
        if (game->build_mode && game->event.key.code == sfMouseLeft)
            manage_build_tower_event(game);
        else if (game->event.key.code == sfMouseLeft)
            select_tower_event(game);
    }
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyA)
            add_enemy(game);
        manage_pause_event(game);
    }
}