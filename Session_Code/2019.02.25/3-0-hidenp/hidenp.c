#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (av[1][0] == '\0')
	{
		write(1, "1\n", 2);
		return (0);
	}
	while (av[2][j])
	{
		if (av[1][i] == '\0')
		{
			write(1, "1\n", 2);
			return (0);
		}
		if (av[1][i] == av[2][j])
			i++;
		j++;
	}
	if (av[1] == '\0')
	{
		write(1, "1\n", 2);
		return (0);
	}
	write(1, "0\n", 2);
	return (0);
}
