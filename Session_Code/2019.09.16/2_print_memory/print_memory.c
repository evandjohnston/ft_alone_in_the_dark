#include <unistd.h>

void	print_byte_ascii(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	print_raw_ascii(const unsigned char *addr, size_t bytes_remaining)
{
	size_t i = 0;
	while (i < 16 && i < bytes_remaining)
	{
		print_byte_ascii(addr[i]);
		i++;
	}
}

void	print_byte_hex(unsigned char c)
{
	char hex_digits[] = "0123456789abcdef";
	write(1, &hex_digits[c / 16], 1);
	write(1, &hex_digits[c % 16], 1);
}

void	print_raw_hex(const unsigned char *addr, size_t bytes_remaining)
{
	size_t i = 0;

	while (i < 16)
	{
		if (i < bytes_remaining)
			print_byte_hex(addr[i]);
		else
			write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0;
	while (i < size)
	{
		print_raw_hex(addr + i, size - i);
		print_raw_ascii(addr + i, size - i);
		write(1, "\n", 1);
		i = i + 16;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}