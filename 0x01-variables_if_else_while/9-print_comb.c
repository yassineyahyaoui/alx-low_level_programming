#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success/correct)
 */
int main(void)

{
char number;


for (number = '0'; number <= '9'; number++)
{
putchar(number);

if (number == '9')
{
break;
}

putchar(',');
putchar (' ');
}

putchar('\n');

return (0);

}
