#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	int digit = n % 10;
	char c = digit + '0';
	write(1, &c, 1);
}

int	check_args(char *str)
{
	if (*str != '-')
		return (0);
	++str;

	int out = 0;
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (-1);
		else if (*str == 'h')
			return (-2);

		out |= 1 << (*str - 'a');
		++str;
	}
	return (out);
}

int	main(int argc, char **argv)
{
	int i = 1;
	int out = 0;
	int	result;

	if (argc == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}

	while (i < argc)
	{
		result = check_args(argv[i]);
		if (result == -1)
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
		else if (result == -2)
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		out |= result;
		++i;
	}
	ft_putnbr(out);
	write(1, "\n", 1);
}