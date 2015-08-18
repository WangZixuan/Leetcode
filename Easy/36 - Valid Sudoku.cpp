/*


Valid Sudoku


Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

@author Zixuan
@date 	2015/8/18
*/

#include <vector>
#include <set>
#define BOARDSIZE 9
using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		//The time complexity is O(n^2).
		//So it doesn't matter how many times I do the double-level loop.

		//Each row.
		for (auto row : board)
		{
			set<char> s;
			for (auto cell : row)
				//Judge and store what I have got.
				if ('.' != cell && s.find(cell) != s.end())//This char appeared before.
					return false;
				else
					s.insert(cell);
		}

		//Each column.
		for (int i = 0; i < BOARDSIZE; ++i)
		{
			set<char> s;
			for (int j = 0; j < BOARDSIZE; ++j)
				if ('.' != board[j][i] && s.find(board[j][i]) != s.end())//This char appeared before.
					return false;
				else
					s.insert(board[j][i]);
		}

		//Each sub-box.
		for (int n = 0; n < BOARDSIZE; ++n)//The number of sub-boxes is n.
		{
			set<char> s;
			for (int i = n / 3 * 3; i <= n / 3 * 3 + 2; ++i)
				for (int j = n % 3 * 3; j <= n % 3 * 3 + 2; ++j)
					if ('.' != board[i][j] && s.find(board[i][j]) != s.end())//This char appeared before.
						return false;
					else
						s.insert(board[i][j]);
		}


		return true;//Valid, but still maybe unsolvable.
	}
};
