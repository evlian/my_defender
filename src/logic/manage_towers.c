/*
** EPITECH PROJECT, 2021
** defender
** File description:
** manage_towers
*/
#include "../../include/defender.h"

tower add_tower_choice(game_instance *game, sfIntRect t, int atk, int r, int atk_tp, int price, char *name, sfColor color)
{
    tower *new = (tower *) malloc(sizeof(tower));

    new->texture = t;
    new->attack = atk;
    new->radius = r;
    new->bullet = game->bullet_types;
    new->position.x = -1;
    new->attack_type = atk_tp;
    new->price = price;
    new->color = color;
    new->name = name;
    new->next = game->tower_choices;
    game->tower_choices = new;
}

void add_tower(game_instance *game, sfVector2f position)
{
    tower *new = (tower *) malloc(sizeof(tower));

    new->position = position;
    new->attack = game->selected_tower->attack;
    new->attack_type = game->selected_tower->attack_type;
    new->radius = game->selected_tower->radius;
    if (new->attack_type == ATK_ARROW || new->attack_type == ATK_MORTAR) {
        new->bullet = game->selected_tower->bullet;
        new->bullet->parent = new;
    }
    new->texture = game->selected_tower->texture;
    new->attack_clock = sfClock_create();
    new->color = game->selected_tower->color;
    new->next = game->towers;
    game->towers = new;
}