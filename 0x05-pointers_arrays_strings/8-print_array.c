#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - prints the first n elements of array a
 * @a: pointer to the first element of an array of integers
 * @n: number of elements to print
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf(", ");

		printf("%d", *(a + i));
	}
	printf("\n");
}
