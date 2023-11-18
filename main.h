#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int hndle_print(const char *fmt, int *i,
va_list list, char buff[], int indicators, int span, int accuracy, int sze);

int prnt_char(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);
int prnt_string(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);
int prnt_percent(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);

int prnt_int(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);
int prnt_bin(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);
int prnt_unsgnd(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);
int prnt_octal(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);
int prnt_hexadec(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);
int print_hexad_upper(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);

int prnt_hexa(va_list types, char map_on[],
char buff[], int indicators, char flag_ch, int span, int accuracy, int sze);

int prnt_nprintable(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);

int prnt_pointer(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);

int gt_flags(const char *format, int *i);
int gt_span(const char *format, int *i, va_list list);
int gt_accuracy(const char *format, int *i, va_list list);
int gt_size(const char *format, int *i);

int prnt_rev(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);

int prnt_rot13(va_list types, char buff[],
	int indicators, int span, int accuracy, int sze);

int handle_print_char(char c, char buff[],
	int indicators, int span, int accuracy, int sze);
int handle_print_string(int is_positive, int ind, char buff[],
	int indicators, int span, int accuracy, int sze);
int print_num(int ind, char bff[], int indicators, int span, int accuracy,
	int length, char padding, char extra_c);
int _pointer(char buff[], int ind, int length,
	int span, int indicators, char padding, char extra_c, int padd_start);

int print_unsgnd(int is_negative, int ind,
char buff[],
	int indicators, int span, int accuracy, int sze);

int printabilty(char);
int append_hex(char, char[], int);
int _digit(char);

long int size_number(long int num, int sze);
long int convert_unsnd(unsigned long int num, int sze);

#endif
