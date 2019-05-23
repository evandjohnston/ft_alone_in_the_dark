#include <stdlib.h>
#include <stdio.h>


int	numlen(int num)
{
	int counter = 0;

	if (num == 0)
		return (1);

	if (num < 0)
		counter++;

	while (num != 0)
	{	
		num = num / 10;
		counter++;
	}
	return (counter);
}


char	*ft_itoa(int nbr)
{
	int size = numlen(nbr);
	char	*hold = (char*)malloc(sizeof(char) * (size + 1));
	int n = 1;
	
	hold[size] = '\0';

	if (nbr == 0)
	{
		hold[0] = '0';
		return (hold);
	}

	if (nbr < 0)
	{
		hold[0] = '-';
		n = -1;
	}
			
	while(nbr != 0)
	{
		hold[size - 1] = n * (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	return (hold);
}
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int		main()
{
	int i = INT_MIN;
	printf("%s\n", ft_itoa(i));

	return (0);
}

/*
42
-42
0


getsize

if number is less than 0.
	counter + 1

if number is zero
	return 1

while the number is not zero
	num = divid it by 10
	counter ++

if zero	
	put zero in array
	done.



get size of 42 (2)
malloc 2 + 1 for array.


apply \0 to the end.

take the array:  42 % 10  + '0' (however many times)
num = 42 / 10 (4)

returning array.


*/
