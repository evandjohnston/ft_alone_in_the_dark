#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char mask = 0b10000000;
	// unsigned char mask = 128;
	// unsigned char mask = 0x80;
	// unsigned char mask = 07;
	// octet & mask
	// => A: 0 (false)
	// or B: some positive number (true)
	while (mask > 0)
	{
		if (octet & mask)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask = mask >> 1;
	}
}

#ifdef TEST
int main(void)
{
	unsigned char octet = 0b00100011;
	print_bits(octet);
	write(1, "\n", 1);
}
#endif
