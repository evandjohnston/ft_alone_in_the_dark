#include <stdio.h>

int check(char a, char b)
{
	if (a == '(' && b == ')')
		return (1);
	else if (a == '[' && b == ']')
		return (1);
	else if (a == '{' && b == '}')
		return (1);
	return (0);
}

int valid_brackets(char *str)
{
	static int matches[1000];
	char buff[1000];
	char c;
	int index = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if (c == '(' || c == '[' || c == '{')
		{
			index += 1;
			buff[index] = c;
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			printf("index: %d\n", index);
			if (index < 0 || check(buff[index], c) == 0)
				continue ;	
			matches[c] += 1;
			buff[index] = '\0';
			index -= 1;
		}
	}
	printf("Matches for \'(\': %d\n", matches[')']);
	printf("Matches for \'[\': %d\n", matches[']']);
	printf("Matches for \'{\': %d\n", matches['}']);
	return (!index);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			printf("For string %s: ", argv[i]);
			printf("%d\n", valid_brackets(argv[i]));
		}
	}
	else
		printf("\n");
	return (0);
}
