// Passed Moulinette 2019.09.02

#include <unistd.h>

void	alpha_mirror(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'M')
			*str = 'Z' - (*str - 'A');
		else if (*str >= 'a' && *str <= 'm')
			*str = 'z' - (*str - 'a');
		else if (*str >= 'N' && *str <= 'Z')
			*str = 'A' + ('Z' - *str);
		else if (*str >= 'n' && *str <= 'z')
			*str = 'a' + ('z' - *str);

		write(1, str, 1);
		++str;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);

	write(1, "\n", 1);
	return (0);
}