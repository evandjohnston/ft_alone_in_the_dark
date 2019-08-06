// Passed Moulinette 2019.08.04

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);

	unsigned int n;
	if (a > b)
		n = a;
	else
		n = b;

	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

//--------------------------------------------------------------
// #include <stdio.h>

// int main(void)
// {
// 	printf("%u\n", lcm(0, 5));
// }