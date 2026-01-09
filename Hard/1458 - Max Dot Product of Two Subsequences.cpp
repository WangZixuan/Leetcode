/*


Max Dot Product of Two Subsequences


Given two arrays nums1 and nums2.
Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).


Example 1:
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.

Example 2:
Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.

Example 3:
Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.

Constraints:
1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 1000

@author Zixuan
@date	2026/1/8
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
	{
		// Hint: Use dynamic programming, define DP[i][j] as the maximum dot product of two subsequences starting in the position i of nums1 and position j of nums2.

		size_t row = nums1.size();
		size_t column = nums2.size();

		vector<vector<int>> dp(row, vector<int>(column));

		dp[row - 1][column - 1] = *nums1.rbegin() * *nums2.rbegin();
		int maxValue = dp[row - 1][column - 1];

		// Initialize last row and last column
		for (int i = column - 2; i >= 0; --i)
		{
			dp[row - 1][i] = max(dp[row - 1][i + 1], nums1[row - 1] * nums2[i]);
			maxValue = max(maxValue, dp[row - 1][i]);
		}
		for (int i = row - 2; i >= 0; --i)
		{
			dp[i][column - 1] = max(dp[i + 1][column - 1], nums1[i] * nums2[column - 1]);
			maxValue = max(maxValue, dp[i][column - 1]);
		}

		for (int i = row - 2; i >= 0; --i)
			for (int j = column - 2; j >= 0; --j)
			{
				dp[i][j] = nums1[i] * nums2[j] > 0 ? 
					maxOfFour(dp[i + 1][j], dp[i][j + 1], nums1[i] * nums2[j], nums1[i] * nums2[j] + dp[i + 1][j + 1]) :
					maxOfFour(dp[i + 1][j], dp[i][j + 1], nums1[i] * nums2[j], dp[i + 1][j + 1]);

				maxValue = max(maxValue, dp[i][j]);
			}

		return maxValue;
	}
private:
	inline int maxOfFour(int a1, int a2, int a3, int a4)
	{
		return max(a1, max(a2, max(a3, a4)));
	}
};
