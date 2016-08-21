/*


 Move Zeroes


Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
	You must do this in-place without making a copy of the array.
	Minimize the total number of operations.

@author Zixuan
@date	2016/8/21
*/


#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums)
	{
		auto zeroCount = 0;
		const auto size = nums.size();
		for (auto i = 0; i < size; ++i)
		{
			nums[i - zeroCount] = nums[i];
			if (0 == nums[i])
				++zeroCount;
		}

		for (auto i = 0; i < zeroCount; ++i)
			nums[size - zeroCount + i] = 0;

	}
};