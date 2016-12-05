/*


Island Perimeter Add to List


You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
Example:
	[[0,1,0,0],
	[1,1,1,0],
	[0,1,0,0],
	[1,1,0,0]]

	Answer: 16

@author Zixuan
@date	2016/12/2
*/
#include <vector>
using namespace std;

class Solution
{
public:
	int islandPerimeter(vector<vector<int>>& grid)
	{
		auto perimeter = 0;

		if (0 == grid.size())
			return 0;

		//If only one column.
		//We know in advance that there are no lakes.
		if (1 == grid[0].size())
		{
			for (auto row : grid)
				perimeter += row[0];
			return perimeter * 2 + 2;
		}

		//Up line of First row.
		auto up = grid[0];
		perimeter = count(up.begin(), up.end(), 1);

		//If only one column.
		if (1 == grid.size())
			return perimeter * 2 + 2;



		auto down = grid[1];
		auto rowIndex = 0;
		while (true)
		{
			//Left line of Left column.
			auto i = 0;
			perimeter += up[i];

			for (; i < up.size() - 1; ++i)
			{
				if (up[i] != down[i])//Vertical.
					++perimeter;
				if (up[i] != up[i + 1])//Horizontal.
					++perimeter;
			}

			//Last column.
			if (up[i] != down[i])
				++perimeter;
			if (1 == up[i])
				++perimeter;

			up = down;
			++rowIndex;
			if (rowIndex == grid.size() - 1)
				break;
			down = grid[rowIndex + 1];
		}

		//Last row, which is up vector now.
		for (auto i = 0; i < up.size() - 1; ++i)
		{
			if (up[i] != up[i + 1])
				++perimeter;
			if (1 == up[i])
				++perimeter;
		}

		perimeter += up[0];
		perimeter += 1 == up[up.size() - 1] ? 2 : 0;

		return perimeter;

	}
};