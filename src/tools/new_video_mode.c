/*
** EPITECH PROJECT, 2021
** defender
** File description:
** new_video_mode
*/
#include "../../include/defender.h"

sfVideoMode new_video_mode(int width, int height, int bits_per_pixel)
{
    sfVideoMode mode;

    mode.height = height;
    mode.width = width;
    mode.bitsPerPixel = bits_per_pixel;
    return mode;
}