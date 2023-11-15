#include "main.h"

/**
 * _printf - our makeshift printf
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	match m[] = {
		{"%c", print_ch}, {"%s", print_string}, {"%%", print_per}
		, {"%i", printi_int}, {"%d", printd_int}, {"%b", print_binary}
		, {"%u", printu_int}, {"%o", print_octal}, {"%x", print_hexad}
		, {"%X", print_HEXAD}
	};
	va_list args;
	int i = 0, length = 0;
	int j;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1]  == '\0'))
		return (-1);
Here:
	while (format[i] == '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].identity[0] == format[i] && m[j].identity[1] == format[i + 1])
			{
				length = length + m[j].f(args);
				i = i + 2;
				goto Here;
			}
				j--;
		}
		_putchar(format[i]);
		i++;
		length++;
	}
	va_end(args);
	return (length);
}
