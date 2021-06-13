/*
** EPITECH PROJECT, 2021
** tools
** File description:
** csv_tools
*/
#include "../../include/my.h"
int **init_2d_array(int rows, int cols);
int get_file_size(char const *file_path);
char *read_file(char *file_path);

int get_num_len(char const *str)
{
    int len = 0;
    int has_num = 0;

    while (str[len] != '\0') {
        if (str[len] >= '0' && str[len] <= '9')
            has_num = 1;
        else if (has_num == 1)
            break;
        len++;
    }
    return len;
}

int get_nbr(char const *str)
{
    int i = 0;
    long number = 0;
    int has_num = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - '0');
            has_num = 1;
        } else if (has_num == 1) {
            break;
        }
        i++;
    }
    return number;
}

int get_cols_len(char *string)
{
    int i = 0;
    int len = 0;

    while (string[i] != '\n' && string[i] != '\0') {
        if (string[i] == ',')
            len++;
        i++;
    }
    return len;
}

int get_rows_len(char *string)
{
    int i = 0;
    int len = 0;

    while (string[i] != '\0') {
        if (string[i] == '\n')
            len++;
        i++;
    }
    return (len == 0) ? 1 : len;
}

int **csv_to_array(char *file_path)
{
    char *csv = read_file(file_path);
    int rows = get_rows_len(csv);
    int cols = get_cols_len(csv);
    int **array = init_2d_array(rows, cols);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < rows) {
        j = 0;
        while (j < cols) {
            array[i][j] = get_nbr(&csv[k]);
            k += get_num_len(&csv[k]);
            j++;
        }
        i++;
    }
    free(csv);
    return array;
}