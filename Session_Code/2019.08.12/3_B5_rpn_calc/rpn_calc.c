#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ISDIGIT(x) (x >= '0' && x <= '9')
#define ISOP(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')

int		do_op(char op, int a, int b)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
		return (a / b);
	else if (op == '%')
		return (a % b);
	else
		return (-1);
}

int		rpn_calc(char *str)
{
	int stack[4096] = {0};
	int stack_i = -1;

	while (*str != '\0')
	{
		if (ISDIGIT(*str) || ( *str == '-' && ISDIGIT(*(str + 1) )))
		{
			++stack_i;
			stack[stack_i] = atoi(str);
			if (*str == '-')
				++str;
			while (ISDIGIT(*str))
				++str;
		}
		else if (ISOP(*str) && stack_i > 0)
		{
			--stack_i;
			if (stack[stack_i + 1] == 0 && (*str == '/' || *str == '%') )
				return (-1);
			stack[stack_i] = do_op(*str, stack[stack_i], stack[stack_i + 1]);
			++str;
		}
		else
			return (-1);
		while (*str == ' ' && *str != '\0')
			++str;
		if (*str != '\0' && *str != ' ' && !ISDIGIT(*str) && !ISOP(*str))
			return (-1);
	}

	if (stack_i != 0)
		return (-1);

	printf("%d\n", stack[stack_i]);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2 || rpn_calc(argv[1]) == -1)
		printf("Error\n");
	return (0);
}