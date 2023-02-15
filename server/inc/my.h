/*
** EPITECH PROJECT, 2021
** B-PSU-200-LYN-2-1-mysokoban-adam.chouag
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <getopt.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>

// ressource //
int my_strlen(char *s);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int length);
void clear_str(char *src);
int my_putstr(char const *str);
void my_putchar(char c);
int	my_put_nbr(int nb);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);

// my_printf  //
int sum_numbers(int n, ...);
int sum_strings_length(int n, ...);
void display_stdarg(char c, va_list my_params, int plus, int *space);
void case_switch2(char c, va_list my_params, int plus, int *space);
void case_switch3(char c, va_list my_params, int plus, int *space);
void case_switch4(char c, va_list my_params, int *space);
void case_switch5(char c, va_list my_params, int *space);
void case_switch6(char c, va_list my_params, int *space);
void case_switch7(char c, va_list my_params, int *space);
void convert_base_unsigned(unsigned int nb, int base, int is_cap);
void convert_base_signed(long nb_bin, int base);
void my_adresse(long nb);
int alloc_int(long nb, int base);
void octal_str(char *str);
void display_starg_format(char *str, int *i, va_list my_params);
void display_stdarg_format_2(char *str, int *i, va_list my_params);
void my_sign(int nb);
void my_hash(int nb, char c);
void void_space(char c, int *i);
void convert_base(long nb, int base, int is_cap);
void space_put(int nb, int *space);
int nb_char(int nb, int base);
int my_printf(char *s, ...);

#endif /* !MY_H_ */
