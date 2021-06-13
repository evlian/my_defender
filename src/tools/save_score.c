/*
** EPITECH PROJECT, 2021
** defender
** File description:
** save_score
*/
#include "../../include/defender.h"

int array_len(int *arr)
{
    int len = 0;

    while (arr[len] != -1) {
        len++;
    }
    return len;
}

void save_score(game_instance *game)
{
    int fd = open("./res/scores.csv", O_WRONLY|O_APPEND);
    char *s = malloc(sizeof(int) * my_num_len(game->score));

    int_to_string(s, game->score);
    write(fd, s, my_num_len(game->score));
    write(fd, ",", 1);
    load_scores(game);
    sort(game->scores, array_len(game->scores), 0);
    free(s);
    close(fd);
}