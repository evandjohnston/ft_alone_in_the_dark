#include <stdio.h>
#include <stdlib.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define IS_OP(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')

int	do_op(int a, int b, char op)
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
		return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\n");
		return (0);
	}

	char *str = av[1];
	int num[4096];
	int i = -1;

	while (*str)
	{
		if (IS_DIGIT(*str))
		{
			num[++i] = atoi(str);
			while (*str && IS_DIGIT(*str))
				++str;
		}
		else if (IS_OP(*str) && i > 0)
		{
			num[i - 1] = do_op(num[i], num[i - 1], *str);
			--i;
			while (*str && IS_OP(*str))
				++str;
		}
		if (*str && *str != ' ')
		{
			printf("Error\n");
			return (0);
		}
		while (*str && *str == ' ')
			++str;
	}

	if (i != 0)
	{
		printf("Error\n");
		return (0);
	}

	printf("%d\n", num[i]);

}
