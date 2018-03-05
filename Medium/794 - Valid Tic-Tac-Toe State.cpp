/*


Valid Tic-Tac-Toe State


A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.
Here are the rules of Tic-Tac-Toe:
Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
	Example 1:
	Input: board = ["O  ", "   ", "   "]
	Output: false
	Explanation: The first player always plays "X".

	Example 2:
	Input: board = ["XOX", " X ", "   "]
	Output: false
	Explanation: Players take turns making moves.

	Example 3:
	Input: board = ["XXX", "   ", "OOO"]
	Output: false

	Example 4:
	Input: board = ["XOX", "O O", "XOX"]
	Output: true

Note:
	board is a length-3 array of strings, where each string board[i] has length 3.
	Each board[i][j] is a character in the set {" ", "X", "O"}.

@author Zixuan
@date	2018/3/4
*/
#include <string>
#include <vector>
using namespace std; 
class Solution 
{
public:
	bool validTicTacToe(vector<string>& board)
	{
		//Check count
		auto xCount = 0, oCount = 0;
		for (auto& line : board)
			for (auto c : line)
				if (c == 'X')
					++xCount;
				else if (c == 'O')
					++oCount;

		if (oCount > xCount || xCount - oCount > 1)
			return false;

		//Check possible winning
		auto xWinning = 0, oWinning = 0;
		for (auto& line : board)
			if (line == "XXX")
				++xWinning;
			else if (line == "OOO")
				++oWinning;

		if (board[0][0] == 'X'&&board[1][0] == 'X'&&board[2][0] == 'X')
			++xWinning;
		if (board[0][1] == 'X'&&board[1][1] == 'X'&&board[2][1] == 'X')
			++xWinning;
		if (board[0][2] == 'X'&&board[1][2] == 'X'&&board[2][2] == 'X')
			++xWinning;

		if (board[0][0] == 'O'&&board[1][0] == 'O'&&board[2][0] == 'O')
			++oWinning;
		if (board[0][1] == 'O'&&board[1][1] == 'O'&&board[2][1] == 'O')
			++oWinning;
		if (board[0][2] == 'O'&&board[1][2] == 'O'&&board[2][2] == 'O')
			++oWinning;

		if (board[0][0] == 'X'&&board[1][1] == 'X'&&board[2][2] == 'X')
			++xWinning;
		if (board[2][0] == 'X'&&board[1][1] == 'X'&&board[0][2] == 'X')
			++xWinning;

		if (board[0][0] == 'O'&&board[1][1] == 'O'&&board[2][2] == 'O')
			++oWinning;
		if (board[2][0] == 'O'&&board[1][1] == 'O'&&board[0][2] == 'O')
			++oWinning;

		if (xWinning + oWinning > 1)
			return false;

		//"XXX", "XOO", "OO "
		if (xWinning == 1 && xCount == oCount)
			return false;

		//"OXX","XOX","OXO"
		if (oWinning == 1 && xCount > oCount)
			return false;

		return true;
	}
};