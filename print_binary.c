#include "main.h"

/**
 * print_binary - converts arguments to binary
 * @val: arguments parameter
 * Return: Binary
 */

int print_binary(va_list val)
{
	int flag = 0;
	int count = 0;
	int i, a, b = 1;
	unsigned int num =  va_arg(val, unsigned int);
	unsigned int d;

	for (i = 0 ; i < 32 ; i++)
	{
		d = ((b << (32 - i)) & num);
		if (d >> (31 - i))
			flag = 1;
		if (flag)
		{
			a = d >> (31 - i);
			_putchar(a + 48);
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar('0');
	}
	return (count);
}
