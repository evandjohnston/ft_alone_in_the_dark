int	sum(int *arr, int size)
{
	int sum = 0;
	int i = 0;

	while (i < size)
	{
		sum += arr[i];
		++i;
	}
	return (sum);
}

int	find_pivot(int *arr, int n)
{
	int sum_left = 0;
	int sum_right = sum(&arr[1], n - 1);
	int i = 0;

	while (i < n)
	{
		if (sum_left == sum_right)
			return (i);
		++i;
		sum_right -= arr[i];
		sum_left += arr[i - 1];
	}
	return (-1);
}

#ifdef TEST
#include <stdio.h>

int	main(void)
{
	int arr[] = {-9, 9, 8};
	printf("%d\n", find_pivot(arr, sizeof(arr) / sizeof(*arr)));

	return (0);
}

#endif