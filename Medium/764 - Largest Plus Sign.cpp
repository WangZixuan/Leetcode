/*


Largest Plus Sign


In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0. 
An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s. 

Examples of Axis-Aligned Plus Signs of Order k:
    Order 1:
    000
    010
    000

    Order 2:
    00000
    00100
    01110
    00100
    00000

    Order 3:
    0000000
    0001000
    0001000
    0111110
    0001000
    0001000
    0000000

Example 1:
    Input: N = 5, mines = [[4, 2]]
    Output: 2
    Explanation:
    11111
    11111
    11111
    11111
    11011
    In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.

Example 2:
    Input: N = 2, mines = []
    Output: 1
    Explanation:
    There is no plus sign of order 2, but there is of order 1.

Example 3:
    Input: N = 1, mines = [[0, 0]]
    Output: 0
    Explanation:
    There is no plus sign, so return 0.

Note:
N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)

@author Zixuan
@date   2018/1/15
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	//Reference: https://leetcode.com/articles/largest-plus-sign/
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines)
	{
		vector<int> oneLine(N, 1);
		vector<vector<int>> grid(N, oneLine);
		for (auto mine : mines)
			grid[mine[0]][mine[1]] = 0;

		auto count = 0;
		for (auto r = 0; r < N; ++r)
		{
			count = 0;
			for (auto c = 0; c < N; ++c)
			{
				count = 0 == grid[r][c] ? 0 : count + 1;
				grid[r][c] = count;
			}

			count = 0;
			for (auto c = N - 1; c >= 0; --c)
			{
				count = 0 == grid[r][c] ? 0 : count + 1;
				grid[r][c] = min(grid[r][c], count);
			}
		}

		auto result = 0;
		for (auto c = 0; c < N; ++c)
		{
			count = 0;
			for (auto r = 0; r < N; ++r)
			{
				count = 0 == grid[r][c] ? 0 : count + 1;
				grid[r][c] = min(grid[r][c], count);
			}

			count = 0;
			for (auto r = N - 1; r >= 0; --r)
			{
				count = 0 == grid[r][c] ? 0 : count + 1;
				grid[r][c] = min(grid[r][c], count);
				result = max(result, grid[r][c]);
			}
		}

		return result;
	}
};