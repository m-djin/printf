#include "main.h"

/**
 * gt_accuracy - finds the accuracy of printing
 * @format: formatted string used to print arguments
 * @i: arguments list to be printed
 * @list: argument list
 * Return: accuracy
 */

int gt_accuracy(const char *format, int *i, va_list list)
{
	int uri = *i + 1;
	int accuracy = -1;

	if (format[uri] != '.')
		return (accuracy);

	accuracy = 0;

	for (uri += 1; format[uri] != '\0'; uri++)
	{
		if (_digit(format[uri]))
		{
			accuracy *= 10;
			accuracy += format[uri] - '0';
		}
		else if (format[uri] == '*')
		{
			uri++;
			accuracy = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = uri - 1;
	return (accuracy);
}
