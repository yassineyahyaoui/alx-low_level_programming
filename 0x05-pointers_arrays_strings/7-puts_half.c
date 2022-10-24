#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @s: pointer to the first character in the string
 */
void puts_half(char *s)
{
	int len, i;

	for (len = 0; s[len]; len++)
		;

	for (i = (len + 1) / 2; i < len; i++)
		_putchar(s[i]);

	_putchar('\n');
}
