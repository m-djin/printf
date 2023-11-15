#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct format
{
	char *identity;
	int (*f)();
} match;

int _putchar(char c);
int _strlen(char *s);
int _strlenc(const char *s);
int print_ch(va_list val);
int print_string(va_list val);
int print_per(void);
int printi_int(va_list args);
int printd_int(va_list args);
int print_binary(va_list val);
int printu_int(va_list args);
int print_octal(va_list val);
int print_hexad(va_list val);
int print_HEXAD(va_list val);
int _printf(const char *format, ...);

#endif
