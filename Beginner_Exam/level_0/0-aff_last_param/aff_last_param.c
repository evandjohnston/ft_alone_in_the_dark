// Passed Moulinette 2019.08.04

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		++i;
	write(1, str, i);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_putstr(argv[argc - 1]);
	write(1, "\n", 1);
	return (0);
}