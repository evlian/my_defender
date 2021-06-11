/*
** EPITECH PROJECT, 2021
** tools
** File description:
** init_2d_array
*/
#include "../../include/my.h"

int **init_2d_array(int rows, int cols)
{
    int i = 0;
    int j = 0;
    int **array = malloc(sizeof(int *) * rows);

    while (i < rows) {
        array[i] = malloc(sizeof(int) * cols);
        j = 0;
        while (j < cols) {
            array[i][j] = 0;
            j++;
        }
        i++;
    }
    return array;
}