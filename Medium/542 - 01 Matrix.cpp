/*


01 Matrix


Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
Example 1:
	Input:
	0 0 0
	0 1 0
	0 0 0
	Output:
	0 0 0
	0 1 0
	0 0 0

Example 2:
	Input:
	0 0 0
	0 1 0
	1 1 1
	Output:
	0 0 0
	0 1 0
	1 2 1

Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

@author Zixuan
@date	2017/12/14
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
	int minOfFour(int i1,int i2,int i3,int i4)
	{
		return min(min(min(i1, i2), i3), i4);
	}

public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
	{
		if (0 == matrix.size() || 0 == matrix[0].size())
			return matrix;

		//Search the min matrix in four dicrections

		//Up
		vector<vector<int>> upSearch(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (unsigned i = 0; i < matrix[0].size(); ++i)//First row
			if (1 == matrix[0][i])
				upSearch[0][i] = INT_MAX;
		for (unsigned i = 1; i < matrix.size(); ++i)
			for (unsigned j = 0; j < matrix[i].size(); ++j)
				if (1 == matrix[i][j])
					upSearch[i][j] = INT_MAX == upSearch[i - 1][j] ? INT_MAX : upSearch[i - 1][j] + 1;

		//Down
		vector<vector<int>> downSearch(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (unsigned i = 0; i < matrix[0].size(); ++i)//Last row
			if (1 == matrix[matrix.size() - 1][i])
				downSearch[matrix.size() - 1][i] = INT_MAX;
		for (int i = matrix.size() - 2; i >= 0; --i)
			for (unsigned j = 0; j < matrix[i].size(); ++j)
				if (1 == matrix[i][j])
					downSearch[i][j] = INT_MAX == downSearch[i + 1][j] ? INT_MAX : downSearch[i + 1][j] + 1;

		//Left
		vector<vector<int>> leftSearch(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (unsigned i = 0; i < matrix.size(); ++i)//First column
			if (1 == matrix[i][0])
				leftSearch[i][0] = INT_MAX;
		for (unsigned j = 1; j < matrix[0].size(); ++j)
			for (unsigned i = 0; i < matrix.size(); ++i)
				if (1 == matrix[i][j])
					leftSearch[i][j] = INT_MAX == leftSearch[i][j - 1] ? INT_MAX : leftSearch[i][j - 1] + 1;

		//Right
		vector<vector<int>> rightSearch(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (unsigned i = 0; i < matrix.size(); ++i)//Last column
			if (1 == matrix[i][matrix[0].size() - 1])
				rightSearch[i][matrix[0].size() - 1] = INT_MAX;
		for (int j = matrix[0].size() - 2; j >= 0; --j)
			for (unsigned i = 0; i < matrix.size(); ++i)
				if (1 == matrix[i][j])
					rightSearch[i][j] = INT_MAX == rightSearch[i][j + 1] ? INT_MAX : rightSearch[i][j + 1] + 1;

		vector<vector<int>> minMatrix(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (unsigned i = 0; i < matrix.size(); ++i)
			for (unsigned j = 0; j < matrix[i].size(); ++j)
			{
				if (1 == matrix[i][j])
					minMatrix[i][j] = minOfFour(upSearch[i][j], downSearch[i][j], leftSearch[i][j], rightSearch[i][j]);
			}

		//From neighbour
		for (unsigned i = 0; i < matrix.size(); ++i)
			for (unsigned j = 0; j < matrix[i].size(); ++j)
			{
				if (1 == matrix[i][j])
				{
					auto minValue = minMatrix[i][j];
					if (i > 0)
						minValue = min(minValue, minMatrix[i - 1][j] + 1);
					if (i < matrix.size() - 1)
						minValue = min(minValue, minMatrix[i + 1][j] + 1);
					if (j > 0)
						minValue = min(minValue, minMatrix[i][j - 1] + 1);
					if (j < matrix[0].size() - 1)
						minValue = min(minValue, minMatrix[i][j + 1] + 1);
					minMatrix[i][j] = minValue;
				}
			}
		return minMatrix;

	}
};
