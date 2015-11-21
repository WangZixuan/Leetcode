/*


House Robber


You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

@author Zixuan
@date	2015/11/21
*/

class Solution 
{
public:
	int rob(vector<int>& nums) 
	{
		if (0 >= nums.size())
			return 0;
		else if (1 == nums.size())
			return nums[0];
		else if (2 == nums.size())
			return max(nums[0], nums[1]);

		//Deal with other situations.
		vector<int> result;
		result.resize(nums.size());
		vector<int> maxSoFar;
		maxSoFar.resize(nums.size());

		result[0] = nums[0];
		result[1] = nums[1];
		maxSoFar[0] = nums[0];
		maxSoFar[1] = max(nums[0], nums[1]);

		for (unsigned int i = 2; i < nums.size(); ++i)
		{
			result[i] = max(maxSoFar[i - 1], maxSoFar[i - 2] + nums[i]);
			maxSoFar[i] = max(result[i - 1], result[i]);
		}

		return result.back();
	}
};