#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
	unsigned int sum = 0;
	char alphanum[]  = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
						"abcdefghijklmnopqrstuvwxyz";
	char pass[30];
	int i;

	srand(time(0));

	for (i = 0; sum < (2772 - 'z' - 1); i++)
	{
		pass[i] = alphanum[rand() % 61];
		sum += pass[i];
	}

	pass[i] = (2772 - sum);
	pass[i+1] = '\0';

	printf("%s\n", pass);

	return (0);
}
