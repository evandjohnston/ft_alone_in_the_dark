#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int	processArg(char *str)
{
	int output = 0;
	int i = 1;

	while (str[i] != '\0')
	{
		if (str[i] == 'h')
			return (-2);
		else if (str[i] >= 'a' && str[i] <= 'z')
			output = output | (1 << (str[i] - 'a'));
		else
			return (-1);
		++i;
	}
	return (output);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}

	int output = 0;
	int i = 1;
	int result;

	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			result = processArg(argv[i]);
			if (result == -1)	//invalid option
			{
				write(1, "Invalid Option\n", 15);
				return (0);
			}
			else if (result == -2)	//usage == -h
			{
				write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
				return (0);
			}
			output = output | result;
		}
		++i;
	}

	ft_putnbr(output);
	write(1, "\n", 1);
	return (0);
}