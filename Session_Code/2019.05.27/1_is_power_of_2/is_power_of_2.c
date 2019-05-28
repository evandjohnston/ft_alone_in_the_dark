int is_power_of_2(unsigned int n)
{
	unsigned int mask =1;
    int flag =0;

	while (mask != 0)
	{
		if ((mask & n) == 1)
         {
           if ((~mask & n) == 0)
              return (1);
           else 
           	  return (0);
         }
         n >>= 1;
	}
	return (0);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", is_power_of_2(10));
	printf("%d\n", is_power_of_2(8));
	return (0);
}

