#include <unistd.h>

/**
 * _putchar - prints the character
 * @c: The character to print
 * Return: 1
 * On error: return -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
