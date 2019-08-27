#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char mask = 0b10000000;

	//octet = 0b10000000
	//mask & octet == 0b10000000 == 128
	while (mask > 0)
	{
		if (mask & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask = mask >> 1;
	}
}

#ifdef TEST
int main(void)
{
	unsigned char test = 2;
	print_bits(test);
	write(1, "\n", 1);
}
#endif