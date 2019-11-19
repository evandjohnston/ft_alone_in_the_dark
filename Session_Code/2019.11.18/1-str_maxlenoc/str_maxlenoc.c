#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		++i;
	return (i);
}

int		ft_strncmp(char *test, char *ref, int n)
{
	int i = 0;

	while (i < n && test[i] && ref[i] && test[i] == ref[i])
		++i;
	if (i == n)
		return (0);
	return (test[i] - ref[i]);
}

int		substrn(char *needle, int test_len, char *haystack)
{
	int hlen = ft_strlen(haystack);
	for (int i = 0; i + test_len <= hlen; ++i)
	{
		if (ft_strncmp(needle, &haystack[i], test_len) == 0)
			return (1);
	}
	return (0);
}

void	str_maxlenoc(int ac, char **av)
{
	int success;
	int max_len = ft_strlen(av[0]);

	// For each length of substr of 0th arg, starting with max len
	for (int test_len = max_len; test_len > 0; --test_len)
	{
		// For each starting position in 0th arg, starting with 0th
		for (int start = 0; start + test_len <= max_len; ++start)
		{
			success = 1;
			//for each other argument, check if test str is substr of other arg
			for (int arg = 1; arg < ac; ++arg)
			{
				// Check if test str is substr of current arg
				if (substrn(&av[0][start], test_len, av[arg]) == 0)
				{
					success = 0;
					break;	// Unnecessary, but it will save a few loops
				}
			}
			if (success == 1)
			{
				write(1, &av[0][start], test_len);
				return;
			}
		}
	}
}

int		main(int ac, char **av)
{
	if (ac >= 2)
		str_maxlenoc(ac - 1, &av[1]);
	write(1, "\n", 1);
}