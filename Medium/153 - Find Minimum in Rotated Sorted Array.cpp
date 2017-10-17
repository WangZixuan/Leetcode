/*


Find Minimum in Rotated Sorted Array


Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.

@author Zixuan
@date	2017/10/17
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int findMin(vector<int>& nums)
	{
		if (1 == nums.size())
			return nums.front();
		//Binary search
		auto start = 0;
		auto end = nums.size() - 1;

		while (start < end)
		{
			auto middle = (start + end) / 2;

			if (start == middle || end == middle)
				break;

			if (nums[start] > nums[middle])
				end = middle;
			else if (nums[middle] > nums[end])
				start = middle;
			else
				return nums[start];
		}

		return min(nums[start], nums[end]);
	}
};