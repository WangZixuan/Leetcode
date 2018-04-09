/*


House Robber II


Note: This is an extension of House Robber.
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.
Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

@author Zixuan
@date	2018/4/9
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int rob(vector<int>& nums)
	{
		auto count = nums.size();

		if (0 >= count)
			return 0;
		if (1 == count)
			return nums[0];
		if (2 == count)
			return max(nums[0], nums[1]);
		if (3 == count)
			return max(nums[0], max(nums[1], nums[2]));

		//Deal with other situations.
		vector<int> result(count);
		vector<int> maxSoFar(count);

		//Situation 1: index 0 is selected.
		result[0] = nums[0];
		result[1] = nums[0];
		maxSoFar[0] = nums[0];
		maxSoFar[1] = nums[0];

		for (unsigned int i = 2; i < count; ++i)
		{
			result[i] = max(maxSoFar[i - 1], maxSoFar[i - 2] + nums[i]);
			maxSoFar[i] = max(result[i - 1], result[i]);
		}
		auto temp = result[count - 2];

		//Situation 2: index 0 is NOT selected.
		result[1] = nums[1];
		result[2] = nums[2];
		maxSoFar[1] = nums[1];
		maxSoFar[2] = max(nums[1], nums[2]);

		for (unsigned int i = 3; i < count; ++i)
		{
			result[i] = max(maxSoFar[i - 1], maxSoFar[i - 2] + nums[i]);
			maxSoFar[i] = max(result[i - 1], result[i]);
		}

		return max(result.back(), temp);
	}
};
