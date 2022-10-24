#include "main.h"

/**
 * _strcpy - copies a string from the source to the buffer
 * @dest: pointer to string destination
 * @src: pointer to string source
 *
 * Return: a pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
