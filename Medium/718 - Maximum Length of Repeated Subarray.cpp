/*


Maximum Length of Repeated Subarray


Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
	Input:
	A: [1,2,3,2,1]
	B: [3,2,1,4,7]
	Output: 3
	Explanation:
	The repeated subarray with maximum length is [3, 2, 1].

Note:
	1 <= len(A), len(B) <= 1000
	0 <= A[i], B[i] < 100

@author Zixuan
@date	2018/6/4
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	//https://leetcode.com/problems/maximum-length-of-repeated-subarray/solution/
	int findLength(vector<int>& A, vector<int>& B)
	{
		//dp[i][j] indicates the longest common prefix of A[i:] and B[j:]
		vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1));

		auto max_value = 0;

		for (int i = A.size() - 1; i >= 0; --i)
			for (int j = B.size() - 1; j >= 0; --j)
			{
				if (A[i] == B[j])
					dp[i][j] = dp[i + 1][j + 1] + 1;
				max_value = max(dp[i][j], max_value);
			}

		return max_value;
	}
};