#include <unistd.h>

int	find_king(char **board, int size, int *krow, int *kcol)
{
	while (*krow < size)
	{
		*kcol = 0;
		while (*kcol < size)
		{
			if (board[*krow][*kcol] == 'K')
				return (1);
			(*kcol)++;
		}
		(*krow)++;
	}
	return (-1);
}

int	check_mate(char **board, int size)
{
	int king_row = 0;
	int king_col = 0;

	if (find_king(board, size, &king_row, &king_col) == -1)
		return (-1);

	int test_row = king_row;
	int test_col = king_col - 1;

	//check upwards
	while (test_col >= 0)
	{
		if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'B' || board[test_row][test_col] == 'P')
			break;
		test_col--;
	}

	//check downwards
	test_col = king_col + 1;
	while (test_col < size)
	{
		if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'B' || board[test_row][test_col] == 'P')
			break;
		test_col++;
	}

	//check leftwards
	test_col = king_col;
	test_row = king_row - 1;
	while (test_row >= 0)
	{
		if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'B' || board[test_row][test_col] == 'P')
			break;
		test_row--;
	}

	//check rightwards
	test_row = king_row + 1;
	while (test_row < size)
	{
		if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'B' || board[test_row][test_col] == 'P')
			break;
		test_row++;
	}

	//check up-leftwards
	test_row = king_row - 1;
	test_col = king_col - 1;
	while (test_col >= 0 && test_row >= 0)
	{
		if (board[test_row][test_col] == 'B' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'P')
			break;
		test_col--;
		test_row--;
	}

	//check up-rightwards
	test_row = king_row - 1;
	test_col = king_col + 1;
	while (test_col < size && test_row >= 0)
	{
		if (board[test_row][test_col] == 'B' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'P')
			break;
		test_col++;
		test_row--;
	}

	//check down-leftwards
	test_row = king_row + 1;
	test_col = king_col - 1;
	while (test_col >= 0 && test_row < size)
	{
		if ((board[test_row][test_col] == 'P' && test_row == king_row + 1) || board[test_row][test_col] == 'B' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'P')
			break;
		test_col--;
		test_row++;
	}

	//check down-rightwards
	test_row = king_row + 1;
	test_col = king_col + 1;
	while (test_col < size && test_row < size)
	{
		if ((board[test_row][test_col] == 'P' && test_row == king_row + 1) || board[test_row][test_col] == 'B' || board[test_row][test_col] == 'Q')
			return (1);
		else if (board[test_row][test_col] == 'R' || board[test_row][test_col] == 'P')
			break;
		test_col++;
		test_row++;
	}

	return (-1);
}

int main(int argc, char **argv)
{
	int ret;
	if (argc > 1)
	{
		ret = check_mate(&argv[1], argc - 1);
		if (ret == -1)
			write(1, "Fail", 4);
		else
			write(1, "Success", 7);
	}
	write(1, "\n", 1);
	return (0);
}