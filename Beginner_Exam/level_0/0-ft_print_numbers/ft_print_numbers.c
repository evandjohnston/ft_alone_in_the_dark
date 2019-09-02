// Passed Moulinette 2019.09.02

#include <unistd.h>

void	ft_print_numbers(void)
{
	write(1, "0123456789", 10);
}

//---------------------------------------------
// int	main(void)
// {
// 	ft_print_numbers();
// 	return (0);
// }