// Passed Moulinette 2019.09.01

int	ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		digit = *str - '0';
		result = result + (digit * sign);
		++str;
	}
	return (result);
}

//-------------------------------------------------
// #include <stdio.h>

// int		main(void)
// {
// 	printf("%d\n", ft_atoi("-12g"));
// }