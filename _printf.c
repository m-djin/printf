#include "main.h"

void prnt_buff(char buff[], int *buff_index);

/**
 * _printf - our makeshift printf function
 * @format: list of arguments passed to the function
 * Return: characters output to the stdout
 */

int _printf(const char *format, ...)
{
	int output = 0, prnt_ch = 0, buff_index = 0;
	int i, accuracy;
	int indicator, span, sze;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0 ; format && format[i] != '\0' ; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				prnt_buff(buff, &buff_index);
			prnt_ch++;
		}

		else
		{
			prnt_buff(buff, &buff_index);
			indicator = gt_flags(format, &i);
			span = gt_flags(format, &i);
			accuracy = gt_accuracy(format, &i, list);
			sze = gt_size(format, &i);
			i++;
			output = hndle_print(format, &i, list
					, buff, indicator, span, accuracy, sze);
			if (output == -1)
				return (-1);
			prnt_ch += output;
		}
	}

	prnt_buff(buff, &buff_index);

	va_end(list);
	return (prnt_ch);
}

/**
 * prnt_buff - prints the contents of buff if there is any
 * @buff: character array
 * @buff_index: point to print out new character
 */

void prnt_buff(char buff[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buff[0], *buff_index);
	*buff_index = 0;
}
