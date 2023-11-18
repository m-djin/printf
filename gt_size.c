#include "main.h"

/**
 * gt_size - calculates the sze to cast the argument
 * @format: formatted string used to print arguments
 * @i: arguments list to be printed
 * Return: accuracy
 */

int gt_size(const char *format, int *i)
{
	int uri = *i + 1;
	int sze = 0;

	if (format[uri] == 'l')
		sze = S_LONG;
	else if (format[uri] == 'h')
		sze = S_SHORT;

	if (sze == 0)
		*i = uri - 1;
	else
		*i = uri;
	return (sze);
}
