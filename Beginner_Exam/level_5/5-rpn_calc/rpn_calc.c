// Passed Moulinette 2019.08.04

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