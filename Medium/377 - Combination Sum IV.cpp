/*


Combination Sum IV


Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
Example:
	nums = [1, 2, 3]
	target = 4

	The possible combination ways are:
	(1, 1, 1, 1)
	(1, 1, 2)
	(1, 2, 1)
	(1, 3)
	(2, 1, 1)
	(2, 2)
	(3, 1)

	Note that different sequences are counted as different combinations.

	Therefore the output is 7.

@author Zixuan
@date	2018/5/31
*/

#include <vector>
using namespace std;

class Solution
{
public:
	int combinationSum4(vector<int>& nums, int target)
	{
		vector<int> possible_ways(target + 1, 0);
		for (auto n : nums)
			if (n <= target)
				possible_ways[n] = 1;

		for (auto i = 1; i < target + 1; ++i)
		{
			auto count = 0;
			for (auto n : nums)
			{
				if (n < i)
					count += possible_ways[i - n];
			}
			possible_ways[i] += count;
		}

		return possible_ways.back();
	}

	//This implementation is TLE.
	int combinationSum4_1(vector<int>& nums, int target)
	{
		long long count = 0;
		for (auto n : nums)
		{
			if (n == target)
				count += 1;
			else if (n < target)
				count += combinationSum4_1(nums, target - n);
		}
		return count;
	}
};
