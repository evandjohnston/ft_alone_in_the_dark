#include <stdio.h>
#include <stdlib.h>

int	is_prime(int n)
{
	if (n == 1)
		return (1);
	int cur = 2;
	while (cur < n)
	{
		if (n % cur == 0)
			return (0);
		++cur;
	}
	return (1);
}

void	fprime(char *str)
{
	int n = atoi(str);
	int cur = 2;
	int is_first = 1;

	if (is_prime(n))
	{
		printf("%d", n);
		return;
	}

	while (cur <= n)
	{
		if (is_prime(cur) && n % cur == 0)
		{
			if (is_first == 0)
				printf("*");
			printf("%d", cur);
			is_first = 0;
			n /= cur;
			continue;
		}
		++cur;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);
	printf("\n");
	return (0);
}