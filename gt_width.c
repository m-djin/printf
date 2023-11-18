#include "main.h"

/**
 * gt_span - calculates the span to print
 * @format: formatted string used to print the arguments
 * @i: arguments list to be printed
 * @list: list of argument
 * Return: span
 */

int gt_span(const char *format, int *i, va_list list)
{
	int uri;
	int span = 0;

	for (uri = *i + 1; format[uri] != '\0'; uri++)
	{
		if (_digit(format[uri]))
		{
			span *= 10;
			span += format[uri] - '0';
		}
		else if (format[uri] == '*')
		{
			uri++;
			span = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = uri - 1;
	return (span);
}
