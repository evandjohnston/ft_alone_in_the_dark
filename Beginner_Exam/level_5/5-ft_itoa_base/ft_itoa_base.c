// This solution should work, but has not been tested by Moulinette

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	unsigned int n = ((value < 0) ? -value : value);
	int i = 0;

	if (value <= 0)
		++i;
	while (n != 0)
	{
		n /= base;
		++i;
	}

	char *out = malloc(sizeof(char) * (i + 1));
	char hex_digits[] = "0123456789ABCDEF";
	out[i] = '\0';
	if (value < 0)
		out[0] = '-';
	if (value == 0)
		out[0] = '0';
	n = ((value < 0) ? -value : value);
	while (n != 0)
	{
		--i;
		out[i] = hex_digits[n % base];
		n /= base;
	}
	return (out);
}

// ------------------------------------------------
// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	int base;
// 	int test;

// 	base = 10;
// 	test = INT_MIN;
// 	printf("%s\n%d\n", ft_itoa_base(test, base), test);
// 	test = -1;
// 	printf("%s\n%d\n", ft_itoa_base(test, base), test);
// 	test = 0;
// 	printf("%s\n%d\n", ft_itoa_base(test, base), test);
// 	test = 1;
// 	printf("%s\n%d\n", ft_itoa_base(test, base), test);
// 	test = INT_MAX;
// 	printf("%s\n%d\n", ft_itoa_base(test, base), test);

// 	base = 8;
// 	test = 28;
// 	printf("%s\n%o\n", ft_itoa_base(test, base), test);
// 	test = INT_MAX;
// 	printf("%s\n%o\n", ft_itoa_base(test, base), test);

// 	base = 16;
// 	test = 0xABCDEF9;
// 	printf("%s\n%x\n", ft_itoa_base(test, base), test);
// 	test = INT_MAX;
// 	printf("%s\n%x\n", ft_itoa_base(test, base), test);
// 	return (0);
// }