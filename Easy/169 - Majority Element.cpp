/*


Majority Element


Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

@author Zixuan
@date	2015/8/26
*/

#include <vector>
using namespace std;
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
	{
        int element = nums[0];
		int times = 1;

		for (unsigned int i = 1; i < nums.size(); ++i)
		{
			if (element == nums[i])
				++times;
			else 
			{
				--times;
				if (times < 0)
				{
					element = nums[i];
					++times;
				}
			}
		}

		return element;
    }
};