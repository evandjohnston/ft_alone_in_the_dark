#include <unistd.h>			//needed for write()

int		main(int ac, char **av)
{
	int		i;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	i = 0;
	while (av[1][i] != '\0')	//keep going until you reach the end of the string
	{
		if ((av[1][i] >= 'A' && av[1][i] <= 'Z') || (av[1][i] >= 'a' && av[1][i] <= 'z'))
			av[1][i] = av[1][i] ^ 32;		//If current char is a letter, swap its case
		write(1, &av[1][i], 1);				//Write a single char
		i++;
	}

	write(1, "\n", 1);						//Don't forget your newline!
	return (0);
}