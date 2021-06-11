/*
** EPITECH PROJECT, 2020
** MyShowStr
** File description:
** Function that displays a string with hex non-printable characters
*/
#include <unistd.h>
int my_showstr(char const *str);
int putnbr_base(int nbr, char *base);
int string_length(char *str);

int string_length(char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int putnbr_base(int nbr, char *base)
{
    int base_length = string_length(base);

    if (nbr < 0) {
        nbr *= -1;
        write(1, "-", 1);
    } else if (nbr == 0) {
        return 0;
    } else {
        putnbr_base(nbr / base_length, base);
    }
    write(1, &base[nbr % base_length], 1);
    return 0;
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32) {
            write(1, "\\", 1);
            if (str[i] < 16)
                write(1, "0", 1);
            putnbr_base(str[i], "0123456789abcdef");
        } else {
            write(1, &str[i], 1);
        }
        i++;
    }
    return 0;
}