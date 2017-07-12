/*


Search Insert Position


Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

@author Zixuan
@date	2017/7/12
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		if (0 == nums.size())
			return 0;

		for (auto i = 0; i < nums.size(); ++i)
			if (nums[i] >= target)
				return i;
		return nums.size();
	}
};
