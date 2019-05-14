#include <unistd.h>

int options(char *str, char *out)
{
	if (str[0] != '-')
		return (-1);
	int i = 1;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (-1);
		else if (str[i] == 'h')
			return (1);
		out[31 - (str[i] - 'a')] = '1';
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}

	int i = 1;
	int result;
	char out[] = "00000000000000000000000000000000\n";
	while (i < ac)
	{
		if (result = options(av[i], out))
		{
			if (result == -1)
				write(1, "Invalid Option\n", 15);
			else if (result == 1)
				write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		++i;
	}

	i = 0;
	while (out[i])
	{
		write(1, out + i, 1);
		++i;
		if (i % 8 == 0 && i < 32)
			write(1, " ", 1);
	}

	return (0);
}