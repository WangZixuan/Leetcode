/*


Continuous Subarray Sum


Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.
Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

@author Zixuan
@date	2018/3/15
*/

#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	//Reference: https://leetcode.com/problems/continuous-subarray-sum/discuss/99499/Java-O(n)-time-O(k)-space
	bool checkSubarraySum(vector<int>& nums, int k)
	{
		if (1 == nums.size())
			return false;
		//Deal with k==0
		if (0 == k)
		{
			for (auto i = 0; i < static_cast<int>(nums.size()) - 1; ++i)
			{
				if (0 == nums[i])
				{
					if (0 == nums[i + 1])
						return true;
				}
			}
			return false;
		}

		//[5, 2, 4], 5
		auto first = 0 == nums[0] % k ? 1 : 0;
		map<int, int> sumMod;
		sumMod.insert(make_pair(0, -1));

		auto sum = 0;
		for (auto i = first; i < nums.size(); ++i)
		{
			auto mod = (sum += nums[i]) % k;

			auto it = sumMod.find(mod);
			if (it == sumMod.end())
				sumMod.insert(make_pair(mod, i));
			else
			{
				if (it->second < i)
					return true;
			}
		}

		return false;
	}
};
