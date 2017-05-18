/*


Surrounded Regions


Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example,
	X X X X
	X O O X
	X X O X
	X O X X

After running your function, the board should be:
	X X X X
	X X X X
	X X X X
	X O X X

@author Zixuan
@date	2017/5/18
*/

#include <vector>
#include <stack>
using namespace std;
//In fact we just need to scan the border.
class Solution
{
public:

	//We use stack to implement DFS.
	void solve(vector<vector<char>>& board)
	{
		if (!check(board))
			return;

		//Deal with four borders.
		for (auto i = 0; i < column; ++i)
			if ('O' == board[0][i])
				flipWithStack(board, 0, i);
		for (auto i = 0; i < column; ++i)
			if ('O' == board[row - 1][i])
				flipWithStack(board, row - 1, i);
		for (auto i = 0; i < row; ++i)
			if ('O' == board[i][0])
				flipWithStack(board, i, 0);
		for (auto i = 0; i < row; ++i)
			if ('O' == board[i][column - 1])
				flipWithStack(board, i, column - 1);

		changeBack(board);

	}
	
	void solve2(vector<vector<char>>& board)
	{
		if (!check(board))
			return;

		//Deal with four borders.
		for (auto i = 0; i < column; ++i)
			flip(board, 0, i);
		for (auto i = 0; i < column; ++i)
			flip(board, row - 1, i);
		for (auto i = 0; i < row; ++i)
			flip(board, i, 0);
		for (auto i = 0; i < row; ++i)
			flip(board, i, column - 1);
		
		changeBack(board);
	}

	

private:
	int row;
	int column;

	bool check(vector<vector<char>>& board)
	{
		row = board.size();

		//Pay attention! Function 'size()' may automatically be deduced to unsigned int.
		//With 'auto' deduction, we will have "reference binding to null pointer of type 'struct value_type'" error
		if (row > 0)
			column = board[0].size();
		else
			return false;

		if (0 == column)
			return false;

		return true;
	}

	void flip(vector<vector<char>>& board, int i, int j)
	{
		if ('O' == board[i][j])
			board[i][j] = '1';
		else
			return;
		
		//TRICKY!
		//If we use 'i>=1', we will have stack overflow and 'Run Time Error'.
		//This works only because the test cases haven't cover all properties, and we should use BFS or my DFS with stack to solve this problem.
		//Reference:
		//https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms/8
		//https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms/11
		if (i > 1 && 'O' == board[i - 1][j])
			flip(board, i - 1, j);
		if (j > 1 && 'O' == board[i][j - 1])
			flip(board, i, j - 1);
		if (i < row - 1 && 'O' == board[i + 1][j])
			flip(board, i + 1, j);
		if (j < column - 1 && 'O' == board[i][j + 1])
			flip(board, i, j + 1);

	}

	void flipWithStack(vector<vector<char>>& board, int i, int j)
	{
		stack<int> position;
		position.push(i*column + j);//[i][j] is 'O'
		
		while (!position.empty())
		{
			auto value = position.top();
			//Value to position
			auto iIndex = value / column;
			auto jIndex = value - iIndex*column;
			board[iIndex][jIndex] = '1';

			position.pop();

			if (iIndex >= 1 && 'O' == board[iIndex - 1][jIndex])
				position.push((iIndex - 1)*column + jIndex);
			if (jIndex >= 1 && 'O' == board[iIndex][jIndex - 1])
				position.push(iIndex*column + jIndex - 1);
			if (iIndex < row - 1 && 'O' == board[iIndex + 1][jIndex])
				position.push((iIndex + 1)*column + jIndex);
			if (jIndex < column - 1 && 'O' == board[iIndex][jIndex + 1])
				position.push(iIndex*column + jIndex + 1);
		}


	}

	void changeBack(vector<vector<char>>& board)
	{
		//Do a loop and change 'O' to 'X'
		for (auto i = 0; i < row; ++i)
			for (auto j = 0; j < column; ++j)
				board[i][j] = board[i][j] == '1' ? 'O' : 'X';
	}
};
