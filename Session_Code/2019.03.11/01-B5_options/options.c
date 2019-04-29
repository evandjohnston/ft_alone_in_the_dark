#include <unistd.h>
//UNTESTED BY MOULINETTE
int		check_flags(char *str, char *arr)
{
	if (*str != '-' || str[0] == '\0' || str[1] == '\0')
		return (-1);
	int i = 1;
	while (str[i])
	{
		if (str[i] == 'h')
			return (1);
		else if (str[i] >= 'a' && str[i] <= 'z')
			arr['z' - str[i] + 6] = '1';
		else
			return (-1);
		i++;
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
	
	char arr[32];
	int j = 0;
	while (j < 32)
	{
		arr[j] = '0';
		j++;
	}

	int arg = 1;
	int out;
	while (arg < ac)
	{
		out = check_flags(av[arg], arr);
		if (out == -1)
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
		else if (out == 1)
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		arg++;
	}
	write(1, arr, 8);
	write(1, " ", 1);
	write(1, arr + 8, 8);
	write(1, " ", 1);
	write(1, arr + 16, 8);
	write(1, " ", 1);
	write(1, arr + 24, 8);
	write(1, "\n", 1);
	return (0);
}
