# ft_itoa_base

## Conceptual Overview
### The Problem
We are asked to write a function that takes arguments of two integers, one representing a number to be converted to a string, and the other representing the base to be used for the conversion. The function performs the conversion and returns a pointer to an allocated string containing the result.

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : ft_itoa_base
	Expected files   : ft_itoa_base.c
	Allowed functions: malloc
	--------------------------------------------------------------------------------

	Write a function that converts an integer value to a null-terminated string
	using the specified base and stores the result in a char array that you must
	allocate.

	The base is expressed as an integer, from 2 to 16. The characters comprising
	the base are the digits from 0 to 9, followed by uppercase letter from A to F.

	For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".

	If base is 10 and value is negative, the resulting string is preceded with a
	minus sign (-). With any other base, value is always considered unsigned.

	Your function must be declared as follows:

	char	*ft_itoa_base(int value, int base);
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [ft_itoa_base.c](ft_itoa_base.c) (passed moulinette on 2019.05.07.)
* [Trinity College: Number Conversion Algorithms writeup](http://www.cs.trincoll.edu/~ram/cpsc110/inclass/conversions.html)
* [Khan Academy: Number Base Conversion Practice video](https://www.youtube.com/watch?v=Fpm-E5v6ddc)

### Approach
* Calculate the number of characters in the output string, then allocate a string of the appropriate size.
	* If the starting number is negative and the base is 10, add 1 for the minus sign; if the starting number is 0, add 1 for the 0 character; if the starting number is negative and the base is not 10, cast the number to an unsigned int before the next step.
	* For each time you are able to divide the absolute value of the starting number by the base before reaching 0, add 1.
* If the starting number is zero or negative, insert the appropriate character at the beginning of the output string.
* Starting with the absolute value of the starting number if the base is 10, or the starting number casted to an unsigned int for all other bases, fill the output string starting from the last character and continuing backwards to the first.
	* Take the current value modulus the base and insert the character corresponding to the result into the output string at the current location.
	* Divide the current value by the base and repeat, filling each character into the output string until the current value reaches 0.
* Return the output string.

### Code
```C
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	unsigned int n = ((base == 10 && value < 0) ? -value : (unsigned int)value);
	int i = 0;

	if (value == 0 || (value < 0 && base == 10))
		++i;
	while (n != 0)
	{
		n /= base;
		++i;
	}

	char *out = malloc(sizeof(char) * (i + 1));
	char hex_digits[] = "0123456789ABCDEF";
	out[i] = '\0';
	if (value < 0 && base == 10)
		out[0] = '-';
	if (value == 0)
		out[0] = '0';
	n = ((base == 10 && value < 0) ? -value : (unsigned int)value);
	while (n != 0)
	{
		--i;
		out[i] = hex_digits[n % base];
		n /= base;
	}
	return (out);
}
```

### Test Cases
```C
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int base;
	int test;

	base = 10;
	test = INT_MIN;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = -1;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = 0;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = 1;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%d\n", ft_itoa_base(test, base), test);

	base = 8;
	test = 28;
	printf("%s\n%o\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%o\n", ft_itoa_base(test, base), test);

	base = 16;
	test = 0xABCDEF9;
	printf("%s\n%x\n", ft_itoa_base(test, base), test);
	test = INT_MAX;
	printf("%s\n%x\n", ft_itoa_base(test, base), test);
	return (0);
}
```