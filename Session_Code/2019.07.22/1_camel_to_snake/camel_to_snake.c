// Discussion led by Jake Parbs (japarbs)

#include <unistd.h>

void putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int i;

	i = -1;
	if (ac == 2)
	{
		while(av[1][++i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				putchar('_');
				putchar(av[1][i] + 32);
			}
			else
				putchar(av[1][i]);
		}
	}
	putchar('\n');
	return (0);
}