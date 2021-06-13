/*
** EPITECH PROJECT, 2021
** defender
** File description:
** manage_bullets
*/
#include "../../include/defender.h"

int has_reached_player(bullet *b)
{
    sfVector2f pos = b->position;
    sfVector2f t_pos = b->target->position;

    return (rect_contains(pos, t_pos) || t_pos.y <= 0 || t_pos.x <= 0);
}

void hit_target(game_instance *game)
{
    bullet *temp = game->bullets;
    bullet *prev;

    while (temp != NULL && has_reached_player(temp)) {
        game->bullets = temp->next;
        free(temp);
        temp = game->bullets;
    }
    while (temp != NULL) {
        while (temp != NULL && !has_reached_player(temp)) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}

void shoot_bullet(game_instance *game, tower *tower, enemy *target)
{
    bullet *b = (bullet *) malloc(sizeof(bullet));

    b->parent = tower;
    b->position = b->parent->position;
    b->target = target;
    b->target_pos = target->position;
    b->texture_rect = tower->bullet->texture_rect;
    b->next = game->bullets;
    game->bullets = b;
}

void move_bullet(bullet *b)
{
    sfVector2f pos = b->position;
    sfVector2f t_pos = b->target_pos;
    float y_diff = abs(t_pos.y - pos.y);
    float x_diff = abs(t_pos.x - pos.x);

    if (x_diff < y_diff) {
        pos.y += pos.y < t_pos.y ? 5.0 : -5.0;
        pos.x += pos.x < t_pos.x ? (5.0 / y_diff * x_diff) :
                                -(5.0 / y_diff * x_diff);
    } else {
        pos.x += pos.x < t_pos.x ? 5.0 : -5.0;
        pos.y += pos.y < t_pos.y ? (5.0 / x_diff * y_diff) :
                                -(5.0 / x_diff * y_diff);
    }
    b->position = pos;
    b->target_pos = t_pos;
}

void move_bullets(game_instance *game)
{
    bullet *head = game->bullets;

    while (head != NULL) {
        head->target_pos = head->target->position;
        move_bullet(head);
        head = head->next;
    }
}