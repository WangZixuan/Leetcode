/*


Partition Equal Subset Sum


Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:
	Input: [1, 5, 11, 5]
	Output: true
	Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
	Input: [1, 2, 3, 5]
	Output: false
	Explanation: The array cannot be partitioned into equal sum subsets.

@author Zixuan
@date	2017/10/12
*/

#include <vector>
#include <numeric>
using namespace std;

class Solution 
{
public:
	bool canPartition(vector<int>& nums)
	{
		if (1 == nums.size())
			return false;
		if (2 == nums.size())
			return nums[0] == nums[1];

		auto sum = accumulate(nums.begin(), nums.end(), 0);
		if (1 == sum % 2)
			return false;

		const auto half = sum >> 1;

		//Now we can split the vector apart iff. some numbers' sum is half.
		//So we turn the problem into "how to get part of the vector whose sum is half"
		//Reference: https://discuss.leetcode.com/topic/63049/my-simple-c-dp-code-with-comments/2
		vector<bool> access(half + 1, false);
		access[0] = true;

		for (auto n : nums)
		{
			for (auto i = half; i >= n; --i)
				if (access[i - n] == true)
					access[i] = true;
		}

		return access[half];
	}
};
