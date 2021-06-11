/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** set_vector
*/
#include "../../include/defender.h"

void set_vector_2i(sfVector2i *vector, int y, int x)
{
    if (x != NO_ARG)
        vector->x = x;
    if (y != NO_ARG)
        vector->y = y;
}

void set_vector_2f(sfVector2f *vector, float y, float x)
{
    if (x != NO_ARG)
        vector->x = x;
    if (y != NO_ARG)
        vector->y = y;
}

void set_vector_3f(sfVector3f *vector, float x, float y, float z)
{
    if (x != NO_ARG)
        vector->x = x;
    if (y != NO_ARG)
        vector->y = y;
    if (z != NO_ARG)
        vector->z = z;
}