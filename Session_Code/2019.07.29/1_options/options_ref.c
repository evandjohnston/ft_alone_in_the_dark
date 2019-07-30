// Passed Moulinette 2019.07.29

#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int		options(char *str, int flags)
{
	int i = 1;
	int bitflag;

	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (-1);
		else if (str[i] == 'h')
			return (-2);
		bitflag = 1 << (str[i] - 'a');
		flags = flags | bitflag;
		++i;
	}
	return (flags);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}

	int i = 1;
	int flags = 0;

	while (i < ac)
	{
		if (av[i][0] == '-' && (flags = options(av[i], flags)) < 0)
		{
			if (flags == -1)
				write(1, "Invalid Option\n", 15);
			else if (flags == -2)
				write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		++i;
	}

	ft_putnbr(flags);
	write(1, "\n", 1);
	return (0);
}