#include "main.h"

/**
 * puts2 - Prints every other character of a string, starting with the first
 * @str: pointer to first character of string
 */
void puts2(char *str)
{
	int i;

	for (i = 0; *str; str++)
	{
		if (i++ % 2 == 0)
			_putchar(*str);
	}
	_putchar('\n');
}
