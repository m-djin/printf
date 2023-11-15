#include "main.h"

/**
 * printi_int - print numbers
 * @args: argument parameter
 * Return: number to be printed
 */

int printi_int(va_list args)
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
 * printd_int - print decimal unsigned int
 * @args: argument parameter
 * Return: number to be printed
 */

int printd_int(va_list args)
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
