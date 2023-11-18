#include "main.h"

/**
 * gt_flags - calculates indicators
 * @format: format string used to print arguments
 * @i: index parameter
 * Return: indicators
 */

int gt_flags(const char *format, int *i)
{
	int j, uri;
	int indicators = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (uri = *i + 1 ; format[uri] != '\0' ; uri++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[uri] == FLAGS_CH[j])
			{
				indicators |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = uri - 1;
	return (indicators);
}
