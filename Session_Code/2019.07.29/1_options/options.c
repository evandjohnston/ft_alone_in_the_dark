#include <unistd.h>
#include <limits.h>

void	options(char *str, int *dict)
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			*dict |= 1 << (str[i] - 'a');
		else
		{
			*dict = INT_MIN;
			return;
		}
	}
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		write(1, "options: abcdefghijklmnopqrstuvwxyz", 35);
	else
	{
		int dict = 0;
		for (int i = 1; i < ac; ++i)
		{
			if (av[i][0] == '-')
				options(&av[i][1], &dict);
		}
		if (dict == INT_MIN)
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
		else if (dict & 128)
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		ft_putnbr(dict);
	}
	write(1, "\n", 1);
}