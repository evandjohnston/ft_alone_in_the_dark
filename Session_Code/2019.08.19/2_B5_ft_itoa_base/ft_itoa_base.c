#include <stdlib.h>

#include <stdio.h>

int		count_digits(unsigned int n, int base)
{
	int len = 0;
	if (n == 0)
		++len;
	while (n > 0)
	{
		++len;
		n /= base;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char digits[] = "0123456789ABCDEF";
	unsigned int n;
	if (base == 10 && value < 0)
		n = -value;
	else
		n = (unsigned int)value;
// 	digits[10] = 'A'

	int len = count_digits(n, base);
	if (base == 10 && value < 0)
		++len;

	char *out = malloc(sizeof(char) * (len + 1));
	out[len] = '\0';

	if (value == 0)
		out[0] = '0';
	if (value < 0 && base == 10)
		out[0] = '-';

	int i = len;
	int digit_index;
	// printf("len: %d\nn: %ld\n", len, n);
	while (n != 0)
	{
		--i;
		digit_index = n % base;
		out[i] = digits[digit_index];
		n /= base;
	}

	return (out);
}

#if 1
#include <printf.h>
#include <limits.h>
int	main(void)
{
	int value = INT_MIN;
	int base = 2;

	printf("%s\n", ft_itoa_base(value, base));
}
#endif