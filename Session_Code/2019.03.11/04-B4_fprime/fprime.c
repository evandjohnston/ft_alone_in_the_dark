#include <stdlib.h>
#include <stdio.h>

int r_u_prime(int n)
{
	int divisor = n/2;
	while(divisor > 1)
	{
		if(n % divisor == 0)
			return(0);
		divisor--;
	}
	return(1);
}

int raise(int num, int power)
{
	if(power == 0)
		return(1);
	int	result = num;
	while(power >= 1)
	{
		result = result*num;
		power--;
	}
	return(result);
}

/*
int main(int ac, char **av)
{
	if(ac == 3)
		printf("%d\n", raise(atoi(av[1]), atoi(av[2]))); 
	return(0);
}
*/

int	highestprimefactor(int num)
{
	int factor = num/2;
	while(factor > 2)
	{
		if(num % factor == 0 && r_u_prime(factor))
			return(factor);
		factor--;
	}
	return(factor);
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int num = atoi(av[1]);
		if(r_u_prime(num))
			printf("%d", num);
		else
		{
			int factor = 2;
			while(factor <= highestprimefactor(num))
			{
				if(num % factor == 0)
				{
					if(r_u_prime(factor))
					{
						printf("%d*", factor);
						int power = 1;
						while(num % (raise(factor, power)) == 0)
						{
							printf("%d*", factor);
							power++;
						}
					}
				}
				factor++;
			}
			//printf("%d", highestprimefactor(num));
		}
	}
	printf("\n");	
	return(0);
}

/*
typedef struct	s_factor {
	struct s_factor *previous;
	int value;
	struct s_factor *next;
} t_factor;

t_factor *add_factor(int value, t_factor *listend)
{
	t_factor newfactor = {NULL, value, NULL};

	if(!listend)
		listend = &newfactor;
	else
	{
		newfactor.previous = listend;
		listend->next = &newfactor;
		listend = listend->next;
	}
	return(listend);
}
*/
/*
int	*get_prime_factors(int n)
{
	int factor = n/2;
	static int stored_factors[n] = {-1};
	int i = 0;
	while(factor > 1)
	{
		if(n % factor == 0)
		{
			if(r_u_prime(factor))
			{
				stored_factors[i] = factor;
				i++;
			}
			else
				get_prime_factors(factor);
		}
	factor--;	
	}
	return(stored_factors);
}
*/
/*
int	main(int ac, char **av)
{
	if(ac == 2)
	{
		int num = atoi(av[1]);

		if(r_u_prime(num))
		{
			printf("%d\n", num);
			return(0);
		}
		else
		{
			get_prime_factors(num);
		}
	}
	printf("\n");
	return(0);
}*/
/*
int main(int ac, char **av)
{
	int i = 1;
	t_factor *beginning = NULL;
	while(i < ac)
	{
		add_factor(atoi(av[i]), beginning);
		i++;
	}
	printf("%d\n", beginning->value);
}*/
