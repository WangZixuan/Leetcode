/*


Product of Array Except Self


Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

@author Zixuan
@date	2017/2/21
*/

#include <vector>
using namespace std;
class Solution 
{
public:
	//Reference: https://discuss.leetcode.com/topic/18864/simple-java-solution-in-o-n-without-extra-space
	vector<int> productExceptSelf(vector<int>& nums) 
	{
		//Multiply from left to right.
		vector<int> result(nums.size(), 1);
		for (auto i = 1; i < nums.size(); ++i)
			result[i] = result[i - 1] * nums[i - 1];

		//Multiply from right to left.
		auto right = 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			result[i] *= right;
			right *= nums[i];
		}

		return result;
	}
};