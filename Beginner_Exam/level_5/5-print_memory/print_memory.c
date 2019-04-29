/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evjohnst <evjohnst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:44:54 by evjohnst          #+#    #+#             */
/*   Updated: 2019/04/27 13:10:51 by evjohnst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Passed moulinette on 2019.04.26.
// Thanks to acarlson (github.com/bombblob) for his suggestions on improving
// this solution.

#include <unistd.h>

void	print_byte_hex(unsigned char c)
{
	char hex_digits[] = "0123456789abcdef";

	write(1, hex_digits + (c / 16), 1);
	write(1, hex_digits + (c % 16), 1);
}

void	print_row_hex(size_t bytes_remaining, const unsigned char *addr)
{
	size_t i = 0;

	while (i < 16)
	{
		if (i < bytes_remaining)
			print_byte_hex(addr[i]);
		else
			write(1, "  ", 2);
		++i;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	print_byte_ascii(unsigned char c)
{
	if (c < 32 || c > 126)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}

void	print_row_ascii(size_t bytes_remaining, const unsigned char *addr)
{
	size_t i = 0;

	while (i < 16 && i < bytes_remaining)
	{
		print_byte_ascii(addr[i]);
		++i;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		print_row_hex(size - i, addr + i);
		print_row_ascii(size - i, addr + i);
		write(1, "\n", 1);
		i += 16;
	}
}



//-----TEST MAIN-----

// int	main(void)
// {
// 	int	tab[10] = {0, 23, 150, 255, 12, 16,  42, 103};
// 	(void)tab;

// 	char str[] = "STRONG STRINGIN' STRING!";
// 	(void)str;

// 	print_memory(tab, sizeof(tab));
// 	write(1, "\n", 1);
// 	print_memory(str, sizeof(str));
// 	return (0);
// }