/*


Single Number


Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

@author Zixuan
@date	2016/9/1
*/

//Reference: https://discuss.leetcode.com/topic/1916/my-o-n-solution-using-xor/2
#include <vector>
using namespace std;
class Solution 
{
public:
	int singleNumber(vector<int>& nums) 
	{
		auto result = 0;
		for (auto i : nums)
			result ^= i;//XOR
		return result;
	}
};