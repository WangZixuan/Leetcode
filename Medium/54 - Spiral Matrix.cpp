/*


Spiral Matrix 


Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order. 
For example,
Given the following matrix: 
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]. 

@author Zixuan
@date	2017/7/11
*/
#include <vector>
using namespace std;

class Solution 
{
public:
	Solution()
	{

		vector<int> spiralOrder(vector<vector<int>>& matrix)
		{
			if (0 == matrix.size())
				return result;
			if (1 == matrix.size())
				return matrix[0];

			return spiralOrder(matrix, 0, 0, matrix[0].size() - 1, matrix.size() - 1);
		}
	}

private:
	vector<int> result;

	vector<int> spiralOrder(vector<vector<int>>& matrix, unsigned left, unsigned up, unsigned right, unsigned down)
	{
		if (up > down || left > right)
			return result;
		if (up == down)
		{
			result.insert(result.end(), matrix[up].begin() + left, matrix[up].begin() + right+1);
			return result;
		}
		if (up + 1 == down)
		{
			result.insert(result.end(), matrix[up].begin() + left, matrix[up].begin() + right+1);
			result.insert(result.end(), matrix[down].rbegin() + left, matrix[down].rbegin() + right+1);
			return result;
		}
		if (left == right)
		{
			//Vertical.
			for (auto i = up; i <= down; ++i)
				result.push_back(matrix[i][right]);
			return result;
		}
		
		result.insert(result.end(), matrix[up].begin() + left, matrix[up].begin() + right + 1);

		//Vertical.
		for (auto i = up + 1; i < down; ++i)
			result.push_back(matrix[i][right]);

		result.insert(result.end(), matrix[down].rbegin() + left, matrix[down].rbegin() + right + 1);

		//Vertical.
		for (auto i = down - 1; i > up; --i)
			result.push_back(matrix[i][left]);

		return spiralOrder(matrix, ++left, ++up, --right, --down);

	}
};