#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	char digit = n % 10;
	digit = digit + '0';
	write(1, &digit, 1);
}

int	main(void)
{
	int i = 1;
	int sentinel;

	while (i <= 100)
	{
		sentinel = 0;
		if (i % 3 == 0)
		{
			write(1, "fizz", 4);
			sentinel = 1;
		}
		if (i % 5 == 0)
		{
			write(1, "buzz", 4);
			sentinel = 1;
		}
		if (i % 7 == 0)
		{
			write(1, "pop", 3);
			sentinel = 1;
		}
		if (sentinel == 0)
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}