/*


Maximum Length of Pair Chain


You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
Example 1:
	Input: [[1,2], [2,3], [3,4]]
	Output: 2
	Explanation: The longest chain is [1,2] -> [3,4]

Note:
The number of given pairs will be in the range [1, 1000].

@author Zixuan
@date	2018/4/3
*/
#include <algorithm>
#include <vector>
using namespace std;

bool mySort(const vector<int>& v1, const vector<int>& v2)
{
	return v1[0] < v2[0];
}

class Solution 
{
public:
	//Reference: https://leetcode.com/problems/maximum-length-of-pair-chain/solution/
	int findLongestChain(vector<vector<int>>& pairs)
	{
		sort(pairs.begin(), pairs.end(), mySort);

		//Here we do not need to record the maximum value so far,.
		//we just record the count.
		vector<int> dp(pairs.size(), 1);

		for (auto j = 1; j < pairs.size(); ++j)
			for (auto i = 0; i < j; ++i)
				if (pairs[i][1] < pairs[j][0])
					dp[j] = max(dp[j], dp[i] + 1);

		return *max_element(dp.begin(), dp.end());
	}

};
