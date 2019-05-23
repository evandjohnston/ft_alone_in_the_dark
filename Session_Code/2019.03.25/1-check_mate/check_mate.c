#include <unistd.h>

int		find_krow(char **board, int rowmax)
{
	int		row = 0;
	int		col = 0;

	while (row <= rowmax)
	{
		col = 0;
		while (board[row][col])
		{
			if (board[row][col] == 'K')
				return (row);
			col++;
		}
		row++;
	}
	return (-1);
}

int		find_kcol(char *line)
{
	int		col = 0;

	while (line[col])
	{
		if (line[col] == 'K')
			return (col);
		col++;
	}
	return (-1);
}

int		check_ortho(char **board, int krow, int kcol, int rowmax, int colmax)
{
	int row = krow;		//Initialize starting position to location of King.
	int col = kcol;

	while (col >= 0)	//Starting from the King and traveling leftward, check for
	{					//pieces that can capture the King from the left: Q and R.
		if (board[row][col] == 'R' || board[row][col] == 'Q')
			return (1);	//The king is captured; return 1.
		else if (board[row][col] == 'P' || board[row][col] == 'B')
			break;	//There is a piece that cannot capture the King; stop checking this direction.
		col--;
	}

	row = krow;		//Reset starting location
	col = kcol;
	while (col <= colmax)	//Check rightward.
	{
		if (board[row][col] == 'R' || board[row][col] == 'Q')
			return (1);
		else if (board[row][col] == 'P' || board[row][col] == 'B')
			break;
		col++;
	}

	row = krow;		//Reset starting location
	col = kcol;
	while (row >= 0)	//Check upward.
	{
		if (board[row][col] == 'R' || board[row][col] == 'Q')
			return (1);
		else if (board[row][col] == 'P' || board[row][col] == 'B')
			break;
		row--;
	}

	row = krow;		//Reset starting location
	col = kcol;
	while (row <= rowmax)	//Check downward.
	{
		if (board[row][col] == 'R' || board[row][col] == 'Q')
			return (1);
		else if (board[row][col] == 'P' || board[row][col] == 'B')
			break;
		row++;
	}

	return (0);		//Didn't find any pieces that can capture the King; return 0.
}

int		check_diag(char **board, int krow, int kcol, int rowmax, int colmax)
{
	int row = krow;
	int col = kcol;

//	Check for pieces that can capture from diagonally up-leftward: Q and B.
	while (--col >= 0 && --row >= 0)	//"--col" permanently subtracts 1 from col,
	{									//THEN the new value of col is compared to 0.
		if (board[row][col] == 'B' || board[row][col] == 'Q')
			return (1);
		else if (board[row][col] == 'P' || board[row][col] == 'R')
			break;	//There is a piece that cannot capture the King; stop checking this direction.
	}

//	Check for pieces that can capture from diagonally up-rightward: Q and B.
	row = krow;
	col = kcol;
	while (++col <= colmax && --row >= 0)
	{
		if (board[row][col] == 'B' || board[row][col] == 'Q')
			return (1);
		else if (board[row][col] == 'P' || board[row][col] == 'R')
			break;
	}

//	Check for pieces that can capture from diagonally down-leftward: Q, B, and P.
	row = krow;
	col = kcol;
	while (--col >= 0 && ++row <= rowmax) // "++row" increments row before comparison
	{
		if (col == kcol - 1 && row == kcol + 1 && board[row][col] == 'P')
			return (1); //P can only capture the King if it is directly adjacent.
		else if (board[row][col] == 'B' || board[row][col] == 'Q')
			return (1);
		else if (board[row][col] == 'P' || board[row][col] == 'R')
			break;	//We still stop looking in this direction if we find P
	}				//>1 space away from K. (We already checked exactly 1 space away).

//	Check for pieces that can capture from diagonally down-rightward: Q, B, and P.
	row = krow;
	col = kcol;
	while (++col <= colmax && ++row <= rowmax)
	{
		if (col == kcol + 1 && row == kcol + 1 && board[row][col] == 'P')
			return (1); //P can only capture the King if it is directly adjacent.
		else if (board[row][col] == 'B' || board[row][col] == 'Q')
			return (1);
		else if (board[row][col] == 'P' || board[row][col] == 'R')
			break;	//We still stop looking in this direction if we find P
	}				//>1 space away from K. (We already checked exactly 1 space away).

	return (0);		//Didn't find any pieces that can capture the King; return 0.
}

int		main(int ac, char **av)
{
//	If no parameters are passed to the program, write a newline and exit.
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

//	Set up variable for board (if you don't want to just use av[1] through av[n])
	char **board = &av[1];

//	Set up max row/column. These will always be the same with a square board.
	int rowmax = ac - 2;	//This is the last row.
	int colmax = rowmax;

//	Find the location of the king
	int krow = find_krow(board, rowmax);	//Find the row the king is in.
	int kcol = find_kcol(board[krow]);		//Find the column the king is in.

//	Starting from the King and going outward, check for pieces that can capture the King
	if (check_ortho(board, krow, kcol, rowmax, colmax) == 1)	//Check up, down, left, right.
		write(1, "Success\n", 8);		//If a piece can capture the king, write "Success"
	else if (check_diag(board, krow, kcol, rowmax, colmax) == 1)//Check diagonally.
		write(1, "Success\n", 8);		//If a piece can capture the king, write "Success"
	else
		write(1, "Fail\n", 5);			//No pieces can capture the king; write "Fail".
	return (0);
}

/*
******TEST CASES******
./check_mate '.....' '.P...' '..K..' '.....' '.....' | cat -e
./check_mate 'Q....' '.....' '..K..' '.....' '.....' | cat -e
./check_mate 'B....' '.....' '..K..' '.....' '.....' | cat -e
./check_mate 'Q....' '.P...' '..K..' '.....' '.....' | cat -e
./check_mate '....B' '.P...' '..K..' '.....' '.....' | cat -e
./check_mate '.....' '.P...' '..K..' '.....' 'B....' | cat -e
./check_mate '.....' '.P...' '..K..' '.....' '....Q' | cat -e
./check_mate '.....' '.P...' '..K..' '.P...' '.....' | cat -e
./check_mate '.....' '.P...' '..K..' '...P.' '.....' | cat -e
./check_mate '..R..' '.....' '..K..' '.....' '.....' | cat -e
./check_mate '..R..' '..P..' '..K..' '.....' '.....' | cat -e
./check_mate '.....' '..P..' 'Q.K..' '.....' '.....' | cat -e
./check_mate '.....' '..P..' '..K.R' '.....' '.....' | cat -e
./check_mate '.....' '..P..' '..K..' '.....' '..Q..' | cat -e
./check_mate '.....' '.....' '..K..' '.....' '.....' | cat -e
./check_mate '.....' '.....' '..K..' '..P..' '..Q..' | cat -e
./check_mate '1230 ' 'mnbzx' 'lpksq' 'iueer' 'jkdsK' | cat -e
./check_mate '1230Q' 'mnbzx' 'lpksq' 'iueer' 'jkdsK' | cat -e
./check_mate '1230 ' 'mnbzx' 'lpksq' 'iueer' 'QkdsK' | cat -e
./check_mate '1230 ' 'mnbzx' 'lpBsq' 'iueer' 'jkdsK' | cat -e
**********************
*/