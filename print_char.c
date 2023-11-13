#include "main.h"
/**
 *print_char - prints characters
 *@va: arguments
 *Return: 0
 */
int print_char(va_list va)
{
	char str;
	str = va_args(va, int);
	_putchar(str);
	return (0);
}
