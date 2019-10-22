#include <stdio.h>
#include <stdlib.h>

#define ISNUM(c) (c >= '0' && c <= '9')
#define ISOP(c) (c == '+' || c == '-' || c == '*' || c == '%' || c == '/')

int	do_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '%')
		return (a % b);
	else if (op == '/')
		return (a / b);
	return (-1);
}

int	rpn_calc(char *str)
{
	int stack[2048];
	int i = 0;
	int k = 0;

	while (str[i])
	{
		if (ISNUM(str[i]) || (str[i] == '-' && ISNUM(str[i + 1])))
		{
			stack[k] = atoi(&str[i]);
			++k;
			if (str[i] == '-')
				++i;
			while (ISNUM(str[i]))
				++i;
		}
		else if (ISOP(str[i]))
		{
			if (k < 2 || ((str[i] == '%' || str[i] == '/') && stack[k - 1] == 0))
				return (-1);
			stack[k - 2] = do_op(stack[k - 2], stack[k - 1], str[i]);
			k--;
		}
		else if (str[i] != ' ' && str[i] != '\0')
			return (-1);
		++i;
	}
	if (k != 1)
		return (-1);
	printf("%d\n", stack[0]);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || rpn_calc(argv[1]) == -1)
		printf("Error\n");
	return (0);
}