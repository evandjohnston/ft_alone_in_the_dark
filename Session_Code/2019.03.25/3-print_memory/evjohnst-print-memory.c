#include <unistd.h>

void	write_char(int c)
{
	if ((c >= -256 && c <= 31 ) || (c >= 127))
		write(1, ".", 1);
	else
		write(1, &c, 1);
}

void	write_num(unsigned int n)
{
	char str[3];
	char *repstr = "0123456789abcdef";
	str[0] = '0';
	str[1] = '0';
	str[2] = '\0';
	str[1] = repstr[n % 16];
	n /= 16;
	str[0] = repstr[n % 16];
	write(1, str, 2);
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0;
	while (i < size)
	{
		if (i != 0 && i % 16 == 0 && i < size)
			write(1, "\n", 1);
		while (1)
		{
			if (i < size)
				write_num(((char *)addr)[i]);
			else
				write(1, "  ", 2);
			i++;
			if (i % 2 == 0)
				write(1, " ", 1);
			if (i % 16 == 0)
			{
				i -= 16;
				break ;
			}
		}
		while (1)
		{
			write_char(((char *)addr)[i]);
			i++;
			if (i % 16 == 0 || i == size)
			{
				break ;
			}
		}
	}
	write(1, "\n", 1);
}