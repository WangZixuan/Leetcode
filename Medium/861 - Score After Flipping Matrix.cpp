/*


Score After Flipping Matrix


We have a two dimensional matrix A where each value is 0 or 1.
A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.
After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
Return the highest possible score.

Example 1:
	Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
	Output: 39
	Explanation:
	Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
	0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Note:
	1 <= A.length <= 20
	1 <= A[0].length <= 20
	A[i][j] is 0 or 1.

@author Zixuan
@date	2018/7/2
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	//Reference: https://leetcode.com/problems/score-after-flipping-matrix/solution/
	int matrixScore(vector<vector<int>>& A) 
	{
		const int R = A.size(), C = A[0].size();
		
		for (auto r = 0; r < R;++r)
			if (A[r][0]==0)
				for (auto& i : A[r])
					i = i == 0 ? 1 : 0;
		
		auto ans = R * 1 << (C - 1);

		for (auto c = 1; c < C; ++c) 
		{
			auto count = 0;
			for (auto r = 0; r < R; ++r)
				if (A[r][c] == 0)
					++count;
			ans += max(count, R - count) * (1 << (C - 1 - c));
		}
		return ans;
	}
};
