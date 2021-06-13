/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** math_tools
*/
#include "../../include/defender.h"

int in_circle(sfVector2f center, int radius, sfVector2f target)
{
    float square_dist = pow((center.x - target.x), 2)
                        + pow((center.y - target.y), 2);
    return square_dist <= pow(radius, 2);
}

int get_dist(sfVector2f center, sfVector2f target)
{
    return pow((center.x - target.x), 2) + pow((center.y - target.y), 2);
}