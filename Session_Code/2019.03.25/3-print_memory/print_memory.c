#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

void	print_hex(unsigned char n) // ?
{
	char *hex = "0123456789abcdef";
	
	ft_putchar(hex[n /16]);
	ft_putchar(hex[n % 16]);
}

void	print_memory(const void *addr, size_t size)
{
	if (addr == NULL)
		return ;

	const char *addr_c = (char *)addr;
	size_t i = 0;
	size_t j = 0;

	while (i < size)
	{
		j = 0;
		while (j < 16) 
		{
			if (i + j < size)
				print_hex(*(addr_c + i + j));
			else
			{
				ft_putchar(' ');
				ft_putchar(' ');
			}
			if (j % 2)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (ft_isprint(addr_c[i + j]))
				ft_putchar(addr_c[i + j]);
			else
				ft_putchar('.');
			j++;
		}
		i += 16;
		ft_putchar('\n');
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}