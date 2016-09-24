/*

3Sum Closest


Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.
	
	For example, given array S = {-1 2 1 -4}, and target = 1.

	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

@author Zixuan
@date	2016/9/24
*/
#include <vector>
#include <algorithm>
using namespace std;
//Reference: https://discuss.leetcode.com/topic/1978/a-n-2-solution-can-we-do-better
class Solution 
{
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		sort(nums.begin(), nums.end());

		if (nums.size() <= 3)
		{
			auto sum = 0;
			for (auto i = 0; i < nums.size(); ++i)
				sum += nums[i];
			return sum;
		}
		auto sum = nums[0] + nums[1] + nums[2];

		for (auto i = 0; i < nums.size(); ++i)
		{
			auto j = i + 1;
			auto k = nums.size() - 1;

			while (j < k)
			{
				auto newsum = nums[i] + nums[j] + nums[k];
				if (abs(target - newsum) < abs(target - sum))
				{
					sum = newsum;
					if (newsum == target)
						return newsum;
				}

				newsum > target ? --k : ++j;
			}
		}

		return sum;

	}
};
