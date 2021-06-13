/*
** EPITECH PROJECT, 2021
** defender
** File description:
** manage_bullets
*/
#include "../../include/defender.h"

int contains(sfVector2f a, sfVector2f b)
{
    sfIntRect rect = vector_to_rect(b, 32, 32);

    return sfIntRect_contains(&rect, a.x, a.y);
}

void hit_target(game_instance *game)
{
    bullet *temp = game->bullets;
    bullet *prev;

    while (temp != NULL && (contains(temp->position, temp->target->position)
                            || temp->target->position.y <= 0
                            || temp->target->position.x <= 0)) {
        game->bullets = temp->next;
        free(temp);
        temp = game->bullets;
    }
    while (temp != NULL) {
        while (temp != NULL &&
                !contains(temp->position, temp->target->position)
                && temp->target->position.y > 0 &&
                temp->target->position.x > 0) {
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
    b->texture_rect = tower->bullet->texture_rect;
    b->next = game->bullets;
    game->bullets = b;
}

void move_bullets(game_instance *game)
{
    bullet *head = game->bullets;

    while (head != NULL) {
        if (head->position.x < head->target->position.x) {
            head->position.x += 5.0;
        } else if (head->position.x > head->target->position.x) {
            head->position.x -= 5.0;
        }
        if (head->position.y < head->target->position.y ) {
            head->position.y += (5.0 / abs(head->target->position.x - head->position.x) *
                                abs(head->target->position.y - head->position.y));
        } else if (head->position.y > head->target->position.y) {
            head->position.y -= (5.0 / abs(head->target->position.x - head->position.x) *
                                abs(head->target->position.y - head->position.y));
        }
        head = head->next;
    }
}