#include "main.h"

/**
 * printability - checks if a character is printable
 * @c: Character to be evaluated.
 * Return: 1 and 0
 */

int printability(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * append_hex - Append hexadecimal code to buffer
 * @buffer: character array
 * @i: point to start appending
 * @ascii_code: Assci
 * Return: 3
 */

int append_hex(char ascii_code, char buffer[], int i)
{
	char map_on[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_on[ascii_code / 16];
	buffer[i] = map_on[ascii_code % 16];
	return (3);
}

/**
 * _digit - checks if a character is a digit
 * @c: Character to be evaluated
 * Return: 1 or 0
 */

int _digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * size_number - converts number to the specified size
 * @num: number to be converted
 * @size: number showing type to be converted
 * Return: Converted value of number
 */

long int size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_unsnd - changes a number to a specified size
 * @num: number to be converted
 * @size: number showing type to be converted
 * Return: converted value of number
 */

long int convert_unsnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
