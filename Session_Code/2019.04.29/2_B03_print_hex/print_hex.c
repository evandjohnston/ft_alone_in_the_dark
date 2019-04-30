#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	unsigned int num = 0;

	char *str = av[1];

	while (*str)
	{
		num += *str - '0';
		str++;
		if (*str)
			num *= 10;
	}

	if (num == 0)
	{
		write(1, "0", 1);
		return (0);
	}

	char hex_digits[] = "0123456789abcdef";
	char out[100];
	int i = 99;
	out[i] = '\0';

	while (num > 0)
	{
		i--;
		out[i] = hex_digits[num % 16];
		num /= 16;
	}

	while (out[i])
	{
		write(1, out + i, 1);
		i++;
	}

	write(1, "\n", 1);

	return (0);
}