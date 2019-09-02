// Passed Moulinette 2019.09.01

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[3]);
		char operator = *argv[2];

		if (operator == '+')
			printf("%d", a + b);
		else if (operator == '-')
			printf("%d", a - b);
		else if (operator == '*')
			printf("%d", a * b);
		else if (b == 0)
			printf("UNDEFINED");
		else if (operator == '/')
			printf("%d", a / b);
		else if (operator == '%')
			printf("%d", a % b);
	}
	printf("\n");
	return (0);
}