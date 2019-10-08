int	    is_power_of_2(unsigned int n)
{
	unsigned int p = 1;

	while (p > 0 && p < n)
		p = p * 2;

	if (p == n)
		return (1);
	return (0);
}

#include <stdio.h>
#include <limits.h>
int	main(void)
{
	printf("%d\n", is_power_of_2(UINT_MAX));
}