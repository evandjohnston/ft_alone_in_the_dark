// Passed Moulinette 2019.08.01

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

char	*find_shortest(char **arr, int size)
{
	int i = 0;
	int min_len = ft_strlen(arr[0]);
	int cur_len;
	char *min = arr[0];
	while (++i < size)
	{
		cur_len = ft_strlen(arr[i]);
		if (min_len > cur_len)
		{
			min_len = cur_len;
			min = arr[i];
		}
	}
	return (min);
}

char	*permute(char *src, int *start_i, int *test_len, int len)
{
	if (*start_i + *test_len >= len)
	{
		*start_i = 0;
		(*test_len)--;
	}
	else
		(*start_i)++;
	return (src + *start_i);
}

int		ft_strncmp(char *a, char *b, int n)
{
	int i = 0;

	while (a[i] && b[i] && a[i] == b[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (a[i] - b[i]);
}

int		check_str(char *needle, char **arr, int arr_size, int test_len)
{
	int i = 0;
	int j;
	int len;
	while (i < arr_size)
	{
		len = ft_strlen(arr[i]);
		j = 0;
		while (j <= len - test_len)
		{
			if (ft_strncmp(needle, arr[i] + j, test_len) == 0)
				break;
			j++;
		}
		if (ft_strncmp(needle, arr[i] + j, test_len) != 0)
				return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		write(1, av[1], ft_strlen(av[1]));
	else if (ac > 2)
	{
		int start_i = 0;
		char *shortest = find_shortest(&av[1], ac - 1);
		int len = ft_strlen(shortest);
		int test_len = len;
		char *test_str = shortest;
		while (test_len > 0 && check_str(test_str, &av[1], ac - 1, test_len) != 1)
			test_str = permute(shortest, &start_i, &test_len, len);
		write(1, test_str, test_len);
	}

	write(1, "\n", 1);
	return (0);
}