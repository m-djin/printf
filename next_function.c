#include "main.h"

/**
 * prnt_unsgnd - prints an unsigned integer
 * @types: List of arguments
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: locates span
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number of characters print.
 */

int prnt_unsgnd(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);

	n = convert_unsnd(n, sze);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buff[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;
	return (print_unsgnd(0, i, buff, indicators, span, accuracy, sze));
}

/**
 * prnt_octal - prints an unsigned integer in its octal notation
 * @types: List of arguments
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: get span
 * @accuracy: accuracy
 * @sze: sze
 * Return: number of chars to print
 */

int prnt_octal(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(span);

	n = convert_unsnd(n, sze);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buff[i--] = (n % 8) + '0';
		n /= 8;
	}

	if (indicators & F_HASH && init_num != 0)
		buff[i--] = '0';

	i++;
	return (print_unsgnd(0, i, buff, indicators, span, accuracy, sze));
}

/**
 * prnt_hexadec - prints an unsigned integer in hexadecimal form
 * @types: arguments list passed
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: span
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number chars printed
 */

int prnt_hexadec(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	return (prnt_hexa(types, "0123456789abcdef", buff,
		indicators, 'x', span, accuracy, sze));
}

/**
 * print_hexad_upper - prints an unsigned integer in upper hexadecimal form
 * @types: arguments pased as list
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: gt span
 * @accuracy: accuracy speciion
 * @sze: sze spification
 * Return: number of chars printd
 */

int print_hexad_upper(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	return (prnt_hexa(types, "0123456789ABCDEF", buff,
		indicators, 'X', span, accuracy, sze));
}

/**
 * prnt_hexa - print a hexadecimal integer in lower or upper case
 * @types: List arguments
 * @map_on: Array of values to
 * @buff: buff array to print
 * @indicators:  calcates active indicators
 * @flag_ch: clculates active indicators
 * @span: gt span
 * @accuracy: accuracy specificatn
 * @sze: sze specificatn
 * @sze: sze specifcatn
 * Return: number char printed
 */

int prnt_hexa(va_list types, char map_on[], char buff[]
	, int indicators, char flag_ch, int span, int accuracy, int sze)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(span);

	n = convert_unsnd(n, sze);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buff[i--] = map_on[n % 16];
		n /= 16;
	}

	if (indicators & F_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;
	return (print_unsgnd(0, i, buff, indicators, span, accuracy, sze));
}


