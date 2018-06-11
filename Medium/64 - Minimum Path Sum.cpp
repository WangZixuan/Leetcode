/*


Minimum Path Sum


Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:
	Input:
	[
	[1,3,1],
	[1,5,1],
	[4,2,1]
	]
	Output: 7
	Explanation: Because the path 1→3→1→1→1 minimizes the sum.

@author Zixuan
@date	2018/6/11
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
	int minPathSum(vector<vector<int>>& grid) 
	{
		if (0 == grid.size())
			return 0;

		vector<vector<int>> sum(grid.size(), vector<int>(grid[0].size()));

		//Initialize
		for (unsigned i = 0; i < grid.size(); ++i)
			sum[i][0] = 0 == i ? grid[i][0] : grid[i][0] + sum[i - 1][0];
		for (unsigned i = 0; i < grid[0].size(); ++i)
			sum[0][i] = 0 == i ? grid[0][i] : grid[0][i] + sum[0][i - 1];

		for (unsigned i = 1; i < grid.size(); ++i)
			for (unsigned j = 1; j < grid[0].size();++j)
				sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];

		return sum.back().back();
	}
};
