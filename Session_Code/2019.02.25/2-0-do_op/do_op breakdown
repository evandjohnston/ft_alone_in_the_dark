do_op breakdown

Conceptual overview:
1. Write a full program that is called from the command line
2. Check if exactly 3 arguments have been given (argc == 4)
	A. If a different number of arguments has been given, print a newline and exit
	B. Otherwise, continue to #3.
3. Convert strings to integers using atoi.
4. Depending on which operator has been given (+, -, *, /, %), perform the appropriate operation on the integers.
5. Print the result of your operation, followed by a newline.

---- C O D E ----

#include <unistd.h>			//needed for write()
#include <???.h>			//Which header do we need for printf?
#include <???.h>			//Which header do we need for atoi?

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

-----------------

Test cases:
./ulstr "PeTEr PIpeR pICKeD A PeCK of pIckLEd PEPPers." | cat -e
./ulstr "[  97A pEcK OF picKLED pePPErS PeTEr PIpeR picked.]  " | cat -e
./ulstr "abc" "dec" | cat -e
./ulstr "" | cat -e
