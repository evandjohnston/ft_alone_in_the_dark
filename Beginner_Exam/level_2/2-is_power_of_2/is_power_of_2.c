// Passed Moulinette 2019.08.03

int	is_power_of_2(unsigned int n)
{
	unsigned long power = 1;

	while (power < n)
		power = 2 * power;

	if (power == n)
		return (1);
	else
		return (0);
}

#if 0
#include <stdio.h>
int	main(void)
{
	unsigned int n = 4294967295;
	printf("Is %u a power of 2? %d\n", n, is_power_of_2(n));
}
#endif