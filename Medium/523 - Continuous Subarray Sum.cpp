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
@date	2017/02/26
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	bool checkSubarraySum(vector<int>& nums, int k) 
	{
		if (0 == k)
		{
			if (nums.size() < 2)
				return false;
			
			auto sum = 0;
			for (auto val : nums)
				sum += val;
			if (0==sum)
				return true;
			
			return false;
		}

		if (nums.size() <= 1)//Attention here, 0==k!
			return false;

		vector<int> temp;

		for (auto i = 1; i < nums.size(); ++i)
		{
			temp.push_back(nums[i - 1] % k);
			for (auto& val : temp)
				val = (val + nums[i]) % k;
			if (isAcceptable(temp))
				return true;
		}
		return false;
	}
private:
	static bool isAcceptable(vector<int>& nums)
	{
		return find(nums.begin(), nums.end(), 0) != nums.end();
	}
};
