/*


Image Smoother


Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.
Example 1:
	Input:
		[[1,1,1],
		[1,0,1],
		[1,1,1]]
	Output:
		[[0, 0, 0],
		[0, 0, 0],
		[0, 0, 0]]
	Explanation:
	For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
	For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
	For the point (1,1): floor(8/9) = floor(0.88888889) = 0

Note:
	The value in the given matrix is in the range of [0, 255].
	The length and width of the given matrix are in the range of [1, 150].

@author Zixuan
@date	2017/9/6
*/

#include <vector>
using namespace std;


class Solution 
{
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
	{
		if (0 == M.size())
			return M;

		int row = M.size();
		int column = M[0].size();
		vector<int> temp(column);
		vector<vector<int>> smoothed(row, temp);

		for (auto i = 0; i < row; ++i)
			for (auto j = 0; j < column; ++j)
				smoothed[i][j] = average(M, i, j, row, column);

		return smoothed;
	}

private:
	int average(vector<vector<int>>& M, int& i, int& j, int& row, int& column)
	{
		auto sum = 0, count = 0;
		auto up = false, down = false, left = false, right = false;
		if (i > 0)
			up = true;
		if (i < row - 1)
			down = true;

		if (j > 0)
			left = true;
		if (j < column - 1)
			right = true;

		if (left)
		{
			sum += M[i][j - 1];
			++count;

			if (up)
			{
				sum += M[i - 1][j - 1];
				++count;
			}
			if (down)
			{
				sum += M[i + 1][j - 1];
				++count;
			}
		}
		if (right)
		{
			sum += M[i][j + 1];
			++count;

			if (up)
			{
				sum += M[i - 1][j + 1];
				++count;
			}
			if (down)
			{
				sum += M[i + 1][j + 1];
				++count;
			}
		}

		if (up)
		{
			sum += M[i - 1][j];
			++count;
		}
		if (down)
		{
			sum += M[i + 1][j];
			++count;
		}

		sum += M[i][j];

		return sum / (count + 1);
	}
};