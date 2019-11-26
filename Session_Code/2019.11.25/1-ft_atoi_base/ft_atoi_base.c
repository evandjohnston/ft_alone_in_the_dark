char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

int	get_digit(char c, int digits_in_base)
{
	char arr[] = "0123456789abcdef";
	int i = 0;
	while (arr[i] != c && i < digits_in_base)
		++i;
	if (i < digits_in_base)
		return (i);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	return (result);
}

#ifdef TEST
#include <stdio.h>

int	main(void)
{
	char test[] = "-0fF";
	printf("%d\n", ft_atoi_base(test, 16));
}

#endif