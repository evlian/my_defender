/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** library
*/
#ifndef MY_H_
#define MY_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
char *my_realloc(char *str, int new_length);
char *my_strdup(char *str);
int my_atoi(char *str);
void *my_memset(void *s, int c,  unsigned int len);
int my_strlenn(char const *str);
int mychar_is_num(char c);
int len(char *str);
int putnbr_base(int nbr, char *base);
int string_length(char *str);
void swap(int *a, int *b);
char *my_strlowcase2(char *str);
int length(char *str);
int str_value_n(char const *str, int n);
char len3(char *str);
int is_prime(int nb);
int rev_str_len(char *str);
int strilen2(char *str);
int decimal_check(char *base);
int my_getnbr2(char const *str);
int my_getbase2(char *str, char *base, int min);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *int_to_string(char *str, int num);
int my_num_len(int num);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

#endif /* MY_H_ */