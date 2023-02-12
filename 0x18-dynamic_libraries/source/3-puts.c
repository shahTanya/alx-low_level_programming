#include "main.h"

/**
 * _puts - prints a string
 * @str: pointer to char type
 */
void _puts(char *str)
{
	for (; *str; str++)
	{
		_putchar(*str);
	}
	_putchar('\n');
}
