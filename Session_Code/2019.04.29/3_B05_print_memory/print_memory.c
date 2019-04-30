#include <unistd.h>

void	print_hex_byte(unsigned char c)
{
	char hex_digits[] = "0123456789abcdef";

	write(1, hex_digits + (c / 16), 1);
	write(1, hex_digits + (c % 16), 1);
}

void	print_hex_digits(size_t max, const unsigned char *addr)
{
	size_t i = 0;

	while (i < 16)
	{
		if (i < max)
			print_hex_byte(addr[i]);
		else
			write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

#include <stdio.h>
void	print_ascii_chars(size_t max, const unsigned char *addr)
{
	size_t i = 0;

	while (i < 16 && i < max)
	{
		// printf("char: %d\n", addr[i]);
		if (addr[i] >= ' ' && addr[i] <= '~')
		{
			write(1, addr + i, 1);
		}
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		print_hex_digits(size - i, addr + i);
		print_ascii_chars(size - i, addr + i);
		write(1, "\n", 1);
		i += 16;
	}
}

//-----------------------
int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}