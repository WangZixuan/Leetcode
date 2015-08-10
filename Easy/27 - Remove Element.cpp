/*


Remove Element


Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

@author Zixuan
@date	2015/8/10
*/

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
	{
		int validSize = nums.size();
		int currentPos = 0;

		while (currentPos <= validSize - 1)
		{
			if (nums[currentPos] == val)
				nums[currentPos] = nums[--validSize];//Here comes it again...
			else
				++currentPos;
		}

		return validSize;
    }
};