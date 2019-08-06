#define MAX(a, b) (((a) > (b)) ? (a) : (b))

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int i = MAX(a, b);

	if (a == 0 || b == 0)
		return (0);


	while (1)
	{
		if (i % a == 0 && i % b == 0)
			return (i);
		++i;
	}
}

#if 1
#include <stdio.h>
int	main(void)
{
	printf("%u\n", lcm(-7, 1));
	printf("%u\n", (unsigned int)(-7));
	printf("%d\n", (int)(4294967289));
}
#endif