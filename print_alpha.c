#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string parameter
 * Return: lenght
 */

int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}

/**
 * _strlenc - returns the length of a constant char
 * @s: string parameter
 * Return: lenght
 */

int _strlenc(const char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}

/**
 * print_ch - prints a character to standard output
 * @val: argument list
 * Return: int
 */

int print_ch(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}

/**
 * print_string - prints a string to standard output
 * @val: arguments list
 * Return: Number of characters printed
 */

int print_string(va_list val)
{
	int len, i;
	char *s;

	s = va_arg(val, char *);

	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0 ; i < len ; i++)
			_putchar(s[i]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0 ; i < len ; i++)
			_putchar(s[i]);
		return (len);
	}
}
/**
 * print_per - print percent sign
 * Return: 0
 */
int print_per(void)
{
	_putchar(37);
	return (0);
}
