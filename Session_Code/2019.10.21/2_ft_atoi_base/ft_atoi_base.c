char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

int	get_digit(char c, int base)
{
	int out;
	if (c >= '0' && c <= '9')
		out = c - '0';
	else if (c >= 'a' && c <= 'f')
		out = c + 10 - 'a';
	else
		return (-1);

	if (out >= 0 && out < base)
		return (out);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int out = 0;
	int sign = 1;
	int i = 0;
	int digit;

	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}

	while ((digit = get_digit(to_lower(str[i]), str_base)) >= 0)
	{
		out *= str_base;
		out += digit * sign;
		++i;
	}
	return (out);
}

#ifdef TEST
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("-2147483648", 10));
}

#endif