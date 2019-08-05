// Passed Moulinette 2019.08.03

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		while (*str != '\0')
		{
			if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm'))
				*str = *str + 13;
			else if (*str >= 'N' && *str <= 'Z')
				*str = 'A' + 12 - ('Z' - *str);
			else if (*str >= 'n' && *str <= 'z')
				*str = 'a' + 12 - ('z' - *str);
			write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}