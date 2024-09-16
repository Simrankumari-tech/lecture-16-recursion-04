
#include <iostream>
using namespace std;

bool isSafe(int i, int j, int n, int board[][10]) {
	// Check the column
	for (int k = 0; k < i ; ++k)
	{
		if (board[k][j]) return false;
	}

	int org_i = i, org_j = j;

	// Lets check the upper right diagonal
	while (i >= 0 and j < n) {
		if (board[i--][j++] == 1) return false;
	}


	// Lets check the upper right diagonal
	i = org_i;
	j = org_j;
	while (i >= 0 and j >= 0) {
		if (board[i--][j--] == 1) return false;
	}
	return true;
}


bool nQueen(int i, int n, int board[][10]) {
	// base case
	if (i == n) {
		// print the board
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				board[i][j] ? cout << "Q " : cout << "_ ";
			}
			cout << endl;
		}
		cout << endl;

		return  false;
	}

	// recursive case
	// for the ith row check for all the columns, if they are safe to place queen
	// we can keep one
	for (int j = 0; j < n; ++j)
	{
		if (isSafe(i, j, n, board)) {
			board[i][j] = 1;// Place the queen here
			// We have placed a queen on board, are we able to place all the remaining
			// queens
			bool kyaBakiPlaceHui = nQueen(i + 1, n, board);
			if (kyaBakiPlaceHui) return true;
			board[i][j] = 0;// remove the queen since we weren't able to place a queen on the
		}
	}

	// jth column
	return false;
}

int main() {

	int board[10][10]  = {0};
	int n = 4;

	nQueen(0, n, board);

	return 0;
}
