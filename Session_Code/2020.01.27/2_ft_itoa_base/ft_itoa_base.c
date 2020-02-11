// Passed Moulinette 2019.09.01

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char hex_digits[] = "0123456789ABCDEF";
	char buf[100];
	int p = 100;
	unsigned int n = ((base == 10 && value < 0) ? -value : (unsigned int)value);

	while (n != 0)
	{
		--p;
		buf[p] = hex_digits[n % base];
		n /= base;
	}

	int len = 100 - p;
	if (value == 0 || (value < 0 && base == 10))
		++len;
	char *out = malloc(sizeof(char) * (len + 1));
	int i = 0;
	if (value < 0 && base == 10)
	{
		out[0] = '-';
		++i;
		--p;
	}
	if (value == 0)
	{
		out[0] = '0';
		++i;
	}

	while (i < len)
	{
		out[i] = buf[p + i];
		++i;
	}
	out[i] = '\0';
	return (out);
}

/* First version: ugly, but functional */

// int		calc_len(unsigned int n, int base)
// {
// 	int len = 0;
// 	if (n == 0)
// 		return (1);
// 	while (n > 0)
// 	{
// 		n /= base;
// 		++len;
// 	}
// 	return (len);
// }

// char	*ft_itoa_base(int value, int base)
// {
// 	unsigned int n;
// 	int len = 0;
// 	if (value < 0 && base != 10)
// 		n = (unsigned int)value;
// 	else if (value < 0)
// 	{
// 		++len;
// 		n = -value;
// 	}
// 	else
// 		n = value;

// 	len += calc_len(n, base);
// 	char *out = malloc(sizeof(char) * (len + 1));
// 	out[len] = '\0';

// 	if (value == 0)
// 		out[0] = '0';
// 	else
// 		out[0] = '-';

// 	char base_digits[] = "0123456789ABCDEF";
// 	while (n > 0)
// 	{
// 		--len;
// 		out[len] = base_digits[n % base];
// 		n /= base;
// 	}
// 	return (out);
// }

#ifdef TEST		// To enable this block of code, compile with `-D TEST`
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int base;
	int test;

	base = 10;
	test = INT_MIN;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = -1;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = 0;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = 1;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);

	base = 8;
	test = 28;
	printf("%s\n%o\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%o\n", ft_itoa_base(test, base), test);

	base = 16;
	test = 0xABCDEF9;
	printf("%s\n%x\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%x\n", ft_itoa_base(test, base), test);
	test = INT_MIN;
	printf("%s\n%x\n", ft_itoa_base(test, base), test);

	base = 9;
	test = -86872362;
	printf("%s\n", ft_itoa_base(test, base));
	return (0);
}
#endif