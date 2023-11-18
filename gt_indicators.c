#include "main.h"

/**
 * gt_flags - calculates indicators
 * @format: format string used to print arguments
 * @i: index parameter
 * Return: indicators
 */

gt_flags(const char *format, int i*)
{
	int i, uri;
	int indicators = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (uri = *i +1 ; format[uri] != '\0' ; uri++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[uri] == FLAGS_CH[i])
			{
				indicators |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}
	*i = uri - 1;
	return (indicators);
}
