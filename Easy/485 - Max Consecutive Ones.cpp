/*


Max Consecutive Ones 


Given a binary array, find the maximum number of consecutive 1s in this array.
Example 1:
	Input: [1,1,0,1,1,1]
	Output: 3
	Explanation: The first two digits or the last three digits are consecutive 1s.
	The maximum number of consecutive 1s is 3.

Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

@author Zixuan
@date	2017/01/15
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	int findMaxConsecutiveOnes(vector<int>& nums) 
	{
		auto count = 0;
		auto current = 0;
		for(auto i:nums)
		{
			if (0 == i)
			{
				count = current > count ? current : count;
				current = 0;
			}
			else
				++current;
		}

		count = current > count ? current : count;
		return count;
	}
};