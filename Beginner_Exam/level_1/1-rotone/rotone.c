// Passed Moulinette 2019.09.01

#include <unistd.h>

void	rotone(char *str)
{
	while (*str != '\0')
	{
		if (*str == 'Z' || *str == 'z')
			*str = *str - ('z' - 'a');
		else if ((*str >= 'A' && *str <= 'Y') || (*str >= 'a' && *str <= 'y'))
			*str = *str + 1;
		write(1, str, 1);
		++str;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);

	write(1, "\n", 1);
}