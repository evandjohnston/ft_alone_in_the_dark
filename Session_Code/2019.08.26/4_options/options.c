#include <stdio.h> //should only use write, not printf, but I'm being lazy
#include <unistd.h>

int	check_flags(char *str, int *out)
{
	int i = 1;
	int shift;

	while (str[i] != '\0')
	{
		if (str[i] == 'h')
		{
			// write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (1);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			shift = str[i] - 'a'; //1
			*out |= (1 << shift); //0000..00010
		}
		else
			return (-1);
		++i;
	}
	return (0);
}

int	options(int argc, char **argv)
{
	int arg_i = 0;
	int out = 0;
	int result;

	while (arg_i < argc)
	{
		if (*argv[arg_i] == '-')
		{
			result = check_flags(argv[arg_i], &out);
			if (result == -1)
			{
				write(1, "Invalid Option\n", 15);
				return (1);
			}
			else if (result == 1)
				return (0);
		}
		++arg_i;
	}
	printf("%d\n", out);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 1 && options(argc - 1, &argv[1]))
	{
		// do nothing
	}
	else
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}