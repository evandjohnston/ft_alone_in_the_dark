# rpn_calc

## Conceptual Overview
### The Problem
We are asked to write a program that takes as argument a string containing a mathemtical expression written in reverse Polish notation. The program evaluates the expression and displays the result if the expression is valid, otherwise displays "Error".

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : rpn_calc
	Expected files   : *.c, *.h 
	Allowed functions: atoi, printf, write, malloc, free
	--------------------------------------------------------------------------------

	Write a program that takes a string which contains an equation written in
	Reverse Polish notation (RPN) as its first argument, evaluates the equation, and
	prints the result on the standard output followed by a newline. 

	Reverse Polish Notation is a mathematical notation in which every operator
	follows all of its operands. In RPN, every operator encountered evaluates the
	previous 2 operands, and the result of this operation then becomes the first of
	the two operands for the subsequent operator. Operands and operators must be
	spaced by at least one space.

	You must implement the following operators : "+", "-", "*", "/", and "%".

	If the string isn't valid or there isn't exactly one argument, you must print
	"Error" on the standard output followed by a newline.

	All the given operands must fit in a "int".

	Examples of formulas converted in RPN:

	3 + 4                   >>    3 4 +
	((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
	50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *

	Here's how to evaluate a formula in RPN:

	1 2 * 3 * 4 -
	2 3 * 4 -
	6 4 -
	2

	Or:

	3 1 2 * * 4 -
	3 2 * 4 -
	6 4 -
	2

	Examples:

	$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
	10$
	$> ./rpn_calc "1 2 3 4 +" | cat -e
	Error$
	$> ./rpn_calc |cat -e
	Error$
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [rpn_calc.c](rpn_calc.c) (passed moulinette on 2019.05.08.)

### Approach
Read through the string given as argument. When a number is found, push it to a stack of numbers. When a mathematical operator is found, pop the top two numbers from the stack and perform the operation on them, pushing the result to the stack. At each step, check for invalid characters or operations, and if one is found print "Error\n" and exit. After reaching the end of the string and performing all operations, if there is one number in the stack, print it; otherwise print "Error\n".

### Code
```C
#include <stdio.h>
#include <stdlib.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define IS_OP(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')

int	do_op(int *cur, char op)
{
	int a = *cur;
	int b = *(cur + 1);

	if (op == '+')
		*cur = a + b;
	else if (op == '-')
		*cur = a - b;
	else if (op == '*')
		*cur = a * b;
	else if (b == 0)	// Check for divide by zero/modulo by zero
		return (-1);
	else if (op == '/')
		*cur = a / b;
	else if (op == '%')
		*cur = a % b;
	return (0);
}

int	rpn_calc(char *str)
{
	int num[4096];
	int i = -1;

	while (*str)
	{
		// Push number to stack of operands
		if (IS_DIGIT(*str) || (*str == '-' && IS_DIGIT(*(str + 1))))
		{
			num[++i] = atoi(str);
			if (*str == '-')
				++str;
			while (*str && IS_DIGIT(*str))
				++str;
		}
		else if (IS_OP(*str) && i > 0)	// Calculate result of operation
		{
			--i;	// Pop top operand from stack
			if (do_op(num + i, *str) == -1)
				return (-1);
			++str;
		}
		if (*str != '\0' && *str != ' ')	// Check for non-digit, non-operator character
			return (-1);
		while (*str != '\0' && *str == ' ')	// Ignore spaces
			++str;
	}

	if (i != 0)	// Check to insure stack contains exactly one number
		return (-1);
	printf("%d\n", num[i]);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || rpn_calc(av[1]) == -1)
		printf("Error\n");
	return (0);
}
```

### Test Cases
* Mismatched number of numbers and operators
* Negative numbers
* Divide/modulo by 0

##### Moulinette's Tests
```
./rpn_calc "2 3 -" "5 6 +"
Error
./rpn_calc "2 -"
Error
./rpn_calc "-"
Error
./rpn_calc "2 5 6 -"
Error
./rpn_calc "3 4 +"
7
./rpn_calc "2 4 + 8 *"
48
./rpn_calc "50 10 25 + -"
15
./rpn_calc "1000 5 2 * /"
100
./rpn_calc "1000 3 %"
1
./rpn_calc "1000 0 /"
Error
./rpn_calc "1000 0 %"
Error
./rpn_calc "-1000 -1 *"
1000
./rpn_calc "-111 45 123 * 26 73 + + - 78 * -85 / 123 -"
5148
./rpn_calc "78 326 542 96 1452 36 965 % - * / - +"
404
```