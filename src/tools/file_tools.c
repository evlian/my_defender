/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** file_tools
*/
#include "../../include/defender.h"

int get_file_size(char const *file_path)
{
    int size;
    struct stat buf;

    if (stat(file_path, &buf) == -1)
        return -1;
    return buf.st_size;
}

char *read_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    int size = get_file_size(file_path);
    char *temp = malloc(sizeof(char) * size + 1);

    temp[size] = '\0';
    read(fd, temp, size);
    close(fd);
    return temp;
}