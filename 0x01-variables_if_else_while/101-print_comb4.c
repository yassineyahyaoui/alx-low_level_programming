#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success/completed)
 */
int main(void)

{
int number_left, number_mid, number_right;
for (number_left = 48; number_left <= 57; number_left++)
{

for (number_mid = 48 ; number_mid <= 57; number_mid++)
{

for (number_right = 48 ; number_right <= 57; number_right++)
{

if ((number_left >= number_mid) || (number_mid >= number_right))
{
continue;
}
else
{
putchar(number_left);
putchar(number_mid);
putchar(number_right);

if ((number_left == 55) && (number_mid == 56) && (number_right == 57))
{
break;
}
else
{
putchar(',');
}

putchar (' ');

}
}
}
}

putchar('\n');

return (0);

}
