/*
** EPITECH PROJECT, 2021
** defender
** File description:
** sort
*/
#include "../../include/defender.h"

int partition (int *arr, int low, int high, int ascending)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j = low;

    while (j <= high - 1) {
        if (arr[j] > pivot && ascending == 0)
            my_swap(&arr[++i], &arr[j]);
        else if (arr[j] < pivot && ascending == 1)
            my_swap(&arr[++i], &arr[j]);
        j++;
    }
    my_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high, int ascending)
{
    int pi;

    if (low < high) {
        pi = partition(arr, low, high, ascending);
        quick_sort(arr, low, pi - 1, ascending);
        quick_sort(arr, pi + 1, high, ascending);
    }
}

int sort(int *list, int size, int ascending)
{
    quick_sort(list, 0, size - 1, ascending);
}