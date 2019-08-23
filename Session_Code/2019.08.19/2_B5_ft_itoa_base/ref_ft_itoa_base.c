// Passed Moulinette 2019.08.04

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	unsigned int n = ((base == 10 && value < 0) ? -value : (unsigned int)value);
	int i = 0;

	if (value == 0 || (value < 0 && base == 10))
		++i;
	while (n != 0)
	{
		n /= base;
		++i;
	}

	char *out = malloc(sizeof(char) * (i + 1));
	char hex_digits[] = "0123456789ABCDEF";
	out[i] = '\0';
	if (value < 0 && base == 10)
		out[0] = '-';
	if (value == 0)
		out[0] = '0';
	n = ((base == 10 && value < 0) ? -value : (unsigned int)value);
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
// 	test = INT_MIN;
// 	printf("%s\n%x\n", ft_itoa_base(test, base), test);

// 	base = 4;
// 	test = -42368063;
// 	printf("%s\n3331132120033001\n", ft_itoa_base(test, base));
// 	return (0);
// }