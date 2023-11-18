#include "main.h"

/**
 * prnt_char - prints a character
 * @types: argument list passed
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: span specification
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number of characters printed
 */

int prnt_char(va_list types
	, char buff[], int indicators, int span, int accuracy, int sze)
{
	char c = va_arg(types, int);

	return (handle_print_char(c, buff, indicators, span, accuracy, sze));
}

/**
 * prnt_string - Prints a string
 * @types: argument list to be passed
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: locate span.
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number of chars printed
 */

int prnt_string(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(accuracy);
	UNUSED(sze);
	UNUSED(indicators);
	UNUSED(buff);
	UNUSED(span);
	if (str == NULL)
	{
		str = "(null)";
		if (accuracy >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (accuracy >= 0 && accuracy < length)
		length = accuracy;

	if (span > length)
	{
		if (indicators & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = span - length; i > 0; i--)
				write(1, " ", 1);
			return (span);
		}
		else
		{
			for (i = span - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (span);
		}
	}
	return (write(1, str, length));
}

/**
 * prnt_percent - prints a percent sign
 * @types: argument list to be passed
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: locate span.
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number of chars printed
 */

int prnt_percent(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	UNUSED(accuracy);
	UNUSED(sze);
	UNUSED(indicators);
	UNUSED(buff);
	UNUSED(types);
	UNUSED(span);
	return (write(1, "%%", 1));
}

/**
 * prnt_int - Print int
 * @types: List of arguments
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: get span.
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number of chars printed
 */

int prnt_int(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = size_number(n, sze);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (handle_print_string(is_negative, i
				, buff, indicators, span, accuracy, sze));
}

/**
 * prnt_bin - prints an unsigned integer
 * @types: Listarguments
 * @buff: buff array to print
 * @indicators:  calculates active indicators
 * @span: span.
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: numbers of characters to print.
 */

int prnt_bin(va_list types, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	unsigned int i, m, n, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(indicators);
	UNUSED(span);
	UNUSED(accuracy);
	UNUSED(sze);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
