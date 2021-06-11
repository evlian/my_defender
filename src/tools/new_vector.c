/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get vector
*/
#include "../../include/defender.h"

sfVector2i new_vector_2i(int x, int y)
{
    sfVector2i vector;

    vector.x = x;
    vector.y = y;
    return vector;
}

sfVector2f new_vector_2f(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return vector;
}

sfVector3f new_vector_3f(float x, float y, float z)
{
    sfVector3f vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
    return vector;
}
