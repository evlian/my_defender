/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** lib
*/
void *my_memset(void *s, int c,  unsigned int len);

void *my_memset(void *s, int c,  unsigned int len)
{
    unsigned char *p = s;

    while (len--) {
        *p++ = (unsigned char)c;
    }
    return s;
}