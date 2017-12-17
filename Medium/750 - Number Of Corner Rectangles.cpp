/*


Number Of Corner Rectangles


Given a grid where each entry is only 0 or 1, find the number of corner rectangles.
A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. 
Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.

Example 1:
Input: grid =
[[1, 0, 0, 1, 0],
[0, 0, 1, 0, 1],
[0, 0, 0, 1, 0],
[1, 0, 1, 0, 1]]
Output: 1
Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].

Example 2:
Input: grid =
[[1, 1, 1],
[1, 1, 1],
[1, 1, 1]]
Output: 9
Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.

Example 3:
Input: grid =
[[1, 1, 1, 1]]
Output: 0
Explanation: Rectangles must have four distinct corners.

Note:
The number of rows and columns of grid will each be in the range [1, 200].
Each grid[i][j] will be either 0 or 1.
The number of 1s in the grid will be at most 6000.

@author Zixuan
@date 2017/12/17
*/

#include <vector>
using namespace std;
class Solution 
{
public:
	//Reference: https://discuss.leetcode.com/topic/114177/short-java-ac-solution-o-m-2-n-with-explanation/2
	//DO NOT BE AFRAID OF BRUTE FORCE
	int countCornerRectangles(vector<vector<int>>& grid) 
	{
		auto count = 0;
		for (unsigned i = 0; i < grid.size() - 1; ++i)
			for (auto j = i + 1; j < grid.size(); ++j)
			{
				auto number = 0;
				for (auto k = 0; k < grid[0].size(); ++k)
					if (grid[i][k] == 1 && grid[j][k] == 1)
						++number;
				if (number > 1)
					count += number*(number - 1) / 2;

			}
		return count;
	}
};
