int 	check_diagonal(char **map, int krow, int kcol, int max)
{
	int row = krow;
	int col = kcol;
	while (row > 0 && col > 0)
	{
		row--;
		col--;
		if (map[row][col] == 'B' || map[row][col] == 'Q')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
			break;
	}

	row = krow;
	col = kcol;
	while (row < max && col < max)
	{
		row++;
		col++;
		if (map[row][col] == 'B' || map[row][col] == 'Q')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
			break;
	}

	row = krow;
	col = kcol;
	while (row < max && col > 0)
	{
		row++;
		col--;
		if (map[row][col] == 'B' || map[row][col] == 'Q' || \
			(map[row][col] == 'P' && row == krow + 1) )
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
			break;
	}

	row = krow;
	col = kcol;
	while (row < max && col < max)
	{
		row++;
		col++;
		if (map[row][col] == 'B' || map[row][col] == 'Q' || \
			(map[row][col] == 'P' && row == krow + 1) )
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
			break;
	}
}

int main (int argc, char **argv)
{
	Parse input into a 2-dimensional array of char
	char **map = &argv[1];

	find coordinates of king
	find maximum length of row/col

	if (check_ortho(map, krow, kcolumn, max))
	{
		write(1, "Success\n", 8);
		return (0);
	}
	if (check_diagonal(map, krow, kcolumn, max))
	{
		write(1, "Success\n", 8);
		return (0);
	}
	write(1, "Fail\n", 5);
}

//test cases
./check_mate 'Q....' '.P...' '..K..' '.....' '....P'