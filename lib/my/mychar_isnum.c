/*
** EPITECH PROJECT, 2020
** IsNum
** File description:
** Checks if char is num
*/
int mychar_is_num(char c);

int mychar_is_num(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}