/*


Target Sum


You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.
Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

@author Zixuan
@date   2018/1/15
*/
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
	int findTargetSumWays(vector<int>& nums, int S)
	{
		auto sum = accumulate(nums.begin(), nums.end(), 0);

		if (sum < S || 0 != (sum - S) % 2)
			return 0;

		auto total = (sum - S) / 2;

		//Next we find how many sets whose sum is total
		sort(nums.begin(), nums.end());
		auto low = lower_bound(nums.begin(), nums.end(), 1);
		auto up = upper_bound(nums.begin(), nums.end(), total);

		auto zeroCount = low - nums.begin();

		if (sum == S)
			return pow(2, zeroCount);

		//Range decrease to [low, up-1]
		vector<int> subVec(low, up);

		//Attention! The index end is changed because we use subVec instead of nums!
		return pow(2, zeroCount) * countTargetSum(subVec, up - nums.begin() - 1 - zeroCount, total);
	}

private:
	int countTargetSum(vector<int>& nums, int end, int S)
	{
		if (0 > end || 0 == end && nums[0] != S)
			return 0;
		if (0 == end && nums[0] == S)
			return 1;

		if (nums[end] == S)
			return 1 + countTargetSum(nums, end - 1, S);

		if (nums[end] > S)
		{
			auto up = upper_bound(nums.begin(), nums.end(), S) - nums.begin();
			return countTargetSum(nums, up - 1, S);
		}

		//nums[end] < S
		return countTargetSum(nums, end - 1, S) + countTargetSum(nums, end - 1, S - nums[end]);
	}

};
