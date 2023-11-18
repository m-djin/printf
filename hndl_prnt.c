#include "main.h"

/**
 * hndle_print - print argument based on it type
 * @fmt: formatted string used to print the arguments
 * @list: arguments list to be printed
 * @ind: index
 * @buff: buff array to print
 * @indicators: calculates active indicators
 * @span: span
 * @accuracy: accuracy specification
 * @sze: sze specification
 * Return: 1, 2;
 */

int hndle_print(const char *fmt, int *ind, va_list list, char buff[]
	, int indicators, int span, int accuracy, int sze)
{
	int i, unknown_lent = 0, prnted_cs = -1;
	fmt_t fmt_types[] = {
		{'c', prnt_char}, {'s', prnt_string}, {'%', prnt_percent},
		{'i', prnt_int}, {'d', prnt_int}, {'b', prnt_bin},
		{'u', prnt_unsgnd}, {'o', prnt_octal}, {'x', prnt_hexadec},
		{'X', print_hexad_upper}, {'p', prnt_pointer}, {'S', prnt_nprintable},
		{'r', prnt_rev}, {'R', prnt_rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buff, indicators, span, accuracy, sze));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_lent += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_lent += write(1, " ", 1);
		else if (span)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_lent += write(1, &fmt[*ind], 1);
		return (unknown_lent);
	}
	return (prnted_cs);
}
