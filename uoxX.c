#include "main.h"

/**
 * printu_int - print unsigned numbers
 * @args: argument parameter
 * Return: number to be printed
 */

int printu_int(va_list args)
{
	int i = 0;
	int n = va_arg(args, int);
	int num, digit, o = n % 10, xp;

	n /= 10;
	num = n;

	if (o < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		o = -o;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			xp =  xp * 10;
			num = num / 10;
		}
		num = n;
		while (xp > 0)
		{
			digit =  num / xp;
			_putchar(digit + '0');
			num = num - (digit * xp);
			xp /= 10;
			i++;
		}
	}
	_putchar(o + '0');
	return (i);
}

/**
 * print_octal - convert to octal  int
 * @val: arg parameter
 * Return: octal int
 */

int print_octal(va_list val)
{
	int i, count = 0;
	int *arr;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int ren = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	arr = malloc(sizeof(int) * count);
	for (i = 0 ; i < count; i++)
	{
		arr[i] = ren % 8;
		ren /= 8;
	}
	for (i = count - 1; i >= 0 ; i--)
		_putchar(arr[i] + '0');
	free(arr);
	return (count);
}

/**
 * print_hexad - convert to hexadecimal integer
 * @val: arg parameter
 * Return: hexadecimal integer
 */

int print_hexad(va_list val)
{
	int i, count = 0;
	int *arr;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int ren = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(sizeof(int) * count);
	for (i = 0 ; i < count; i++)
	{
		arr[i] = ren % 16;
		ren /= 16;
	}
	for (i = count - 1; i >= 0 ; i--)
	{
		if (arr[i] > 9)
		arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}

/**
 * print_HEXAD - convert to hexadecimal integer in upper case
 * @val: arg parameter
 * Return: hexadecimal integer
 */

int print_HEXAD(va_list val)
{
	int i, count = 0;
	int *arr;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int ren = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(sizeof(int) * count);
	for (i = 0 ; i < count; i++)
	{
		arr[i] = ren % 16;
		ren /= 16;
	}
	for (i = count - 1; i >= 0 ; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 7;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
