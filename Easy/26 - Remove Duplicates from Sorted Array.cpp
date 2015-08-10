/*


Remove Duplicates from Sorted Array


Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

@author Zixuan
@date	2015/8/10
*/

#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (0 == nums.size() || 1 == nums.size())
			return nums.size();

		//nums.size() >= 2.
		int valid = 0;
		int current = 1;
		while (current < nums.size())
		{
			if (nums[valid] == nums[current])//The same
				++current;
			else//Not the same
				nums[++valid] = nums[current++];//How could I write such code...-_-||
		}
		return valid + 1;
	}
};
