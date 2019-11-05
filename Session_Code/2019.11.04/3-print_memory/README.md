# print_memory

## Conceptual Overview
### The Problem
We are asked to write a function that takes arguments of a memory location and a number of bytes to print, and displays the requested number of bytes from the given location as both hexadecimal values and ASCII characters in the following format:
```
0000 0000 1700 0000 9600 0000 ff00 0000 ................$
0c00 0000 1000 0000 2a00 0000 6700 0000 ........*...g...$
0000 0000 0000 0000                     ........$
```

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : print_memory
	Expected files   : print_memory.c
	Allowed functions: write
	--------------------------------------------------------------------------------

	Write a function that takes (const void *addr, size_t size), and displays the
	memory as in the example.

	Your function must be declared as follows:

	void	print_memory(const void *addr, size_t size);

	---------
	$> cat main.c
	void	print_memory(const void *addr, size_t size);

	int	main(void)
	{
		int	tab[10] = {0, 23, 150, 255,
		              12, 16,  42, 103};

		print_memory(tab, sizeof(tab));
		return (0);
	}
	$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
	0000 0000 1700 0000 9600 0000 ff00 0000 ................$
	0c00 0000 1000 0000 2a00 0000 6700 0000 ........*...g...$
	0000 0000 0000 0000                     ........$
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [print_memory.c](print_memory.c) (passed moulinette on 2019.04.26.)
* [man hexdump](http://man7.org/linux/man-pages/man1/hexdump.1.html)

### Approach
Read from the memory address passed as argument in groups of up to 16 bytes. For each group:
* Print the value of each byte as a 2-digit hexadecimal number, inserting a space every 2 bytes or 4 digits, and padding groups of fewer than 16 bytes with spaces to insure a 40-character total.
* For each byte, if its value corresponds to a printable character, print that character, otherwise print a period ('.').
* Print a newline character ('\n').

### Code
```C
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
```

### Test Cases
```C
int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  42, 103};
	(void)tab;

	char str[] = "STRONG STRINGIN' STRING!";
	(void)str;

	print_memory(tab, sizeof(tab));
	write(1, "\n", 1);
	print_memory(str, sizeof(str));
	return (0);
}
```