#include <unistd.h>

// 1010 1100 ==> 0010 1101

unsigned char	swap_first_last_bits(unsigned char octet)
{
	unsigned char mask;
	unsigned char result;
	unsigned char temp;

	mask = 0b10000000;
	result = (octet & mask) >> 7;

	mask = 0b00000001;
	temp = (octet & mask) << 7;
	// result: 	0000 0001 <==> 0000 0001
	// temp: 	1000 0000 <==> 0000 0000
	result |= temp;
	// result:	1000 0001 <==> 0000 0001

	mask = 0b01111110;
	temp = octet & mask;
	// result:	1000 0001 <==> 0000 0001
	// temp: 	0111 1110 <==> 0010 1100
	result |= temp;
	// result:	1111 1111 <==> 0010 1101

	return (result);
}