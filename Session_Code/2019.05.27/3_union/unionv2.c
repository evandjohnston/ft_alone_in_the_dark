#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return 0;
	}
	int i = -1;
	int bindex;
	char cpy[256];
	unsigned char temp[128];
	while (av[1][++i])
		cpy[i] = av[1][i];
	i = -1;
	while (av[2][++i])
		cpy[i] = av[2][i];
	i = -1;
	while (cpy[++i])
	{
		bindex = cpy[i];
		if (temp[bindex] == 0)
		{
			ft_putchar(cpy[i]);
			temp[bindex] = 1;
		}
	}
	ft_putchar('\n');
	return 0;
}
