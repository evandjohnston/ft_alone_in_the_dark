#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1234 % 10 = 4
// 1234 / 10 = 123

#define 🌮 "hello from taco 🌮"

void		print_hex_recursive(int num)
{
	char	hex[] = "0123456789abcdef";

	printf("num current value: %d\n", num);
	printf("hex[%d]: %c\n", num % 16, hex[num %16]);
	if (num >= 16)
		print_hex_recursive(num / 16);
	printf("%c", hex[num % 16]);
}
// 🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮🌮
int			main(int argc, char *argv[])
{
	printf("%s\n", 🌮);
	if (argc == 2)
		print_hex_recursive(atoi(argv[1]));
	printf("\n");
	return (0);
}