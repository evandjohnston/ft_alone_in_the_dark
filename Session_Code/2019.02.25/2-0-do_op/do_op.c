#include <unistd.h>			//needed for write()
#include <stdio.h>			//Which header do we need for printf?
#include <stdlib.h>			//Which header do we need for atoi?

int		main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("\n");
		return (0);
	}

	int		a = atoi(av[1]);	//Get first number by calling atoi on string av[1]
	int		b = atoi(av[3]);	//Get second number by calling atoi on string av[3]
	char	op = av[2][0];		//Get operator from first char of av[2]

	int		result = 0;
	if (op == '+')				//Do operation depending on value of the variable op
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '*')
		result = a * b;
	else if (op == '/')
		result = a / b;
	else if (op == '%')
		result = a % b;

	printf("%d\n", result);		//Print the result and a newline
	return (0);
}