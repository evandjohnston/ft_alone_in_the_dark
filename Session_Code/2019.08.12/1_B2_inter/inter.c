#include <unistd.h>

void	inter(char *a, char *b)
{
	int allowed[128] = {0};
	int i = 0;
	int allowed_index;

	while (b[i] != '\0')
	{
		allowed_index = b[i];
		allowed[allowed_index] = 1;
		++i;
	}

	i = 0;
	while (a[i] !='\0')
	{
		allowed_index = a[i];
		if (allowed[allowed_index] == 1)
		{
			write(1, &a[i], 1);
			allowed[allowed_index] = 0;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);

	write(1, "\n", 1);
	return(0);
}