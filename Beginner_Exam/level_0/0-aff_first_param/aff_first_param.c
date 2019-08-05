// Passed Moulinette 2019.08.04

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	return (0);
}