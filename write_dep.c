#include "main.h"
#include "main.h"

/**
 * handle_print_char - Prints a string
 * @c: character
 * @buff: buff array to handle print
 * @indicators: calculate active indicators
 * @span: locate span
 * @accuracy: accuracy specification
 * @sze: sze specification
 *
 * Return: umber of chars printed.
 */
int handle_print_char(char c, char buff[]
		, int indicators, int span, int accuracy, int sze)
{
	int i = 0;
	char padding = ' ';

	UNUSED(accuracy);
	UNUSED(sze);

	if (indicators & F_ZERO)
		padding = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (span > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < span - 1; i++)
			buff[BUFF_SIZE - i - 2] = padding;

		if (indicators & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - i - 1], span - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], span - 1) +
					write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

/**
 * handle_print_string - Prints a string
 * @is_negative: argument list
 * @ind: character index
 * @buff: buff array to handle printing
 * @indicators:  calculates active indicators
 * @span: locate span
 * @accuracy: accuracy specification
 * @sze: size specification
 * Return: number of character printed
 */

int handle_print_string(int is_negative, int ind, char buff[]
		, int indicators, int span, int accuracy, int sze)
{
	int length = BUFF_SIZE - ind - 1;
	char padding = ' ', xtr_ch = 0;

	UNUSED(sze);

	if ((indicators & F_ZERO) && !(indicators & F_MINUS))
		padding = '0';
	if (is_negative)
		xtr_ch = '-';
	else if (indicators & F_PLUS)
		xtr_ch = '+';
	else if (indicators & F_SPACE)
		xtr_ch = ' ';

	return (print_num(ind, buff, indicators, span, accuracy,
		length, padding, xtr_ch));
}

/**
 * print_num - print a number from bufffer
 * @ind: Index find the number on the buff
 * @buff: buff
 * @indicators: indicators
 * @span: span
 * @prec: accuracy specification
 * @length: Number length
 * @padding: padding char
 * @extra_c: extra char
 * Return: number of printed character
 */

int print_num(int ind, char buff[]
		, int indicators, int span, int prec
		, int length, char padding, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && span == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = padding = ' '; /* span is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padding = ' ';
	while (prec > length)
		buff[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (span > length)
	{
		for (i = 1; i < span - length + 1; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (indicators & F_MINUS && padding == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], length) + write(1, &buff[1], i - 1));
		}
		else if (!(indicators & F_MINUS) && padding == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], length));
		}
		else if (!(indicators & F_MINUS) && padding == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], length));
}

/**
 * print_unsgnd - prints an unsigned number
 * @is_negative: number indicating if the num is negative
 * @ind: index at which the number starts in the buff
 * @buff: character array
 * @indicators: indicators specifier
 * @span: span specification
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: number of characters written
 */

int print_unsgnd(int is_negative, int ind, char buff[]
		, int indicators, int span, int accuracy, int sze)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(sze);

	if (accuracy == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0);

	if (accuracy > 0 && accuracy < length)
		padding = ' ';

	while (accuracy > length)
	{
		buff[--ind] = '0';
		length++;
	}

	if ((indicators & F_ZERO) && !(indicators & F_MINUS))
		padding = '0';

	if (span > length)
	{
		for (i = 0; i < span - length; i++)
			buff[i] = padding;

		buff[i] = '\0';

		if (indicators & F_MINUS)
		{
			return (write(1, &buff[ind], length) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], length));
		}
	}

	return (write(1, &buff[ind], length));
}

/**
 * _pointer - locate and store a memory address
 * @buff: character array
 * @ind: index at which the number starts in the buff
 * @length: Length of number
 * @span: width specification
 * @indicators: indicators specification
 * @padding: Character representing the padding
 * @extra_c: Character representing extra char
 * @padd_start: index at which padding should start
 * Return: number of written characters
 */

int _pointer(char buff[], int ind, int length, int span
		, int indicators, char padding, char extra_c, int padd_start)
{
	int i;

	if (span > length)
	{
		for (i = 3; i < span - length + 3; i++)
			buff[i] = padding;
		buff[i] = '\0';
		if (indicators & F_MINUS && padding == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], length) + write(1, &buff[3], i - 3));
		}
		else if (!(indicators & F_MINUS) && padding == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], length));
		}
		else if (!(indicators & F_MINUS) && padding == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], length - (1 - padd_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
