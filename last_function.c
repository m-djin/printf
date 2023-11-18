#include "main.h"

/**
 * prnt_pointer - prints the value of a pointer
 * @types: arguments passed
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: span
 * @accuracy: accuracy specication
 * @sze: sze speication
 * Return: number of caracterprinted.
 */

int prnt_pointer(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	char xtra_c = 0, paddin = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_b = 1;
	unsigned long num_addr;
	char map_on[] = "0123456789abcdef";
	void *addr = va_arg(types, void *);

	UNUSED(sze);
	UNUSED(span);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(accuracy);

	num_addr = (unsigned long)addr;

	while (num_addr > 0)
	{
		buff[ind--] = map_on[num_addr % 16];
		num_addr /= 16;
		length++;
	}

	if ((indicators & F_ZERO) && !(indicators & F_MINUS))
		paddin = '0';
	if (indicators & F_PLUS)
		xtra_c = '+', length++;
	else if (indicators & F_SPACE)
		xtra_c = ' ', length++;

	ind++;
	return (_pointer(buff, ind, length,
		span, indicators, paddin, xtra_c, padd_b));
}

/**
 * prnt_nprintable - prints ascii in hexadecimal of non printable
 * @types: Listof arguments
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: span
 * @accuracy: accuracy
 * @sze: sze specification
 * Return: num of chars printed
 */

int prnt_nprintable(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	int i = 0, off = 0;
	char *str = va_arg(types, char *);

	UNUSED(indicators);
	UNUSED(span);
	UNUSED(accuracy);
	UNUSED(sze);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (printability(str[i]))
			buff[i + off] = str[i];
		else
			off += append_hex(str[i], buff, i + off);

		i++;
	}

	buff[i + off] = '\0';
	return (write(1, buff, i + off));
}

/**
 * prnt_rev - prints a string in reverse
 * @types: list of argument
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: gt span
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: numbers of characters to be printed
 */

int prnt_rev(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	char *str;
	int i, cont = 0;

	UNUSED(indicators);
	UNUSED(span);
	UNUSED(buff);
	UNUSED(sze);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(accuracy);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		cont++;
	}
	return (cont);
}

/**
 * prnt_rot13 - prints a string in rot13
 * @types: List  of arguments
 * @buff: buff array to  print
 * @indicators:  Calculates active indicators
 * @span: gt span
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number of character printd
 */
int prnt_rot13(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	char x, *str;
	unsigned int j, i;
	int count = 0;
	char into[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outo[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buff);
	UNUSED(indicators);
	UNUSED(span);
	UNUSED(accuracy);
	UNUSED(sze);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; into[j]; j++)
		{
			if (into[j] == str[i])
			{
				x = outo[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!into[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
