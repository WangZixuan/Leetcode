/*


Array Partition I


Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
	say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
	Input: [1,4,3,2]

	Output: 4
	Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].

@author Zixuan
@date	2017/9/8
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
	int arrayPairSum(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		auto sum = 0;
		for (unsigned i = 0; i < nums.size(); i = i + 2)
			sum += nums[i];
		return sum;
	}
};