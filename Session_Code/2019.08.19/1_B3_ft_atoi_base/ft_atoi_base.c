char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	get_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
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

	while ((digit = get_digit(to_lower(*str))) >= 0)
	{
		result *= str_base;
		result += digit * sign;
		++str;
	}
	return (result);
}

#if 0
#include <stdio.h>
int	main(void)
{
	char test[] = "FF";
	int	base = 13;
	printf("test: %s\nreal: %d\n", test, ft_atoi_base(test, base));
}
#endif