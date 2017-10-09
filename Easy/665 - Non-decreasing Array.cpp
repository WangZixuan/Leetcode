/*


Non-decreasing Array


Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
Example 1:
	Input: [4,2,3]
	Output: True
	Explanation: You could modify the first
	4
	to
	1
	to get a non-decreasing array.

Example 2:
	Input: [4,2,1]
	Output: False
	Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].

@author Zixuan
@date	2017/10/9
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	bool checkPossibility(vector<int>& nums)
	{
		auto index = -1;
		for (auto i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] <= nums[i + 1])
				continue;

			if (index == -1)
				index = i;
			else
				return false;
		}

		//Some special cases.
		if (0 >= index)
			return true;

		//3,3,2,4
		if (index < nums.size() - 2 && nums[index] <= nums[index + 2])
			return true;

		//1,2,4,5,3
		if (index == nums.size() - 2)
			return true;

		return nums[index - 1] <= nums[index + 1];
	}
};
