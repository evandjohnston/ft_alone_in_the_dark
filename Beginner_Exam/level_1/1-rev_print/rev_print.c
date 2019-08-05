// Passed Moulinette 2019.08.04

#include <unistd.h>

void	rev_print(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		++i;
	--i;
	while (i >= 0)
	{
		write(1, str + i, 1);
		--i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_print(argv[1]);

	write(1, "\n", 1);
	return (0);
}