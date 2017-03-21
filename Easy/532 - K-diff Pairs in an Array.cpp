/*


K-diff Pairs in an Array


Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
Example 1:
	Input: [3, 1, 4, 1, 5], k = 2
	Output: 2
	Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
	Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:
	Input:[1, 2, 3, 4, 5], k = 1
	Output: 4
	Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
	Input: [1, 3, 1, 5, 4], k = 0
	Output: 1
	Explanation: There is one 0-diff pair in the array, (1, 1).

Note:
	The pairs (i, j) and (j, i) count as the same pair.
	The length of the array won't exceed 10,000.
	All the integers in the given input belong to the range: [-1e7, 1e7].

@author Zixuan
@date	2017/3/21
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int findPairs(vector<int>& nums, int k) 
	{
		if (0 == nums.size() || k < 0)
			return 0;

		sort(nums.begin(), nums.end());

		if (0 == k)
			return findPairsWithZeroK(nums, k);

		return findPairsWithNonzeroK(nums, k);
	}

private:

	static int findPairsWithZeroK(vector<int>& nums, int k)
	{
		auto currentValue = -1e7 - 1;
		auto count = 0;

		for (auto i = 0; i < nums.size(); ++i)
		{
			if (currentValue != nums[i])
				currentValue = nums[i];
			else if (currentValue == nums[i] && i == 1)
				++count;
			else if (currentValue == nums[i] && i >= 2 && nums[i] != nums[i - 2])
				++count;
		}

		return count;
	}

	static int findPairsWithNonzeroK(vector<int>& nums, int k)
	{
		auto numsAddtion(nums);
		for_each(numsAddtion.begin(), numsAddtion.end(), [&](int& d) { d += k; });//Amazing, in fact I don't know what happened.

		auto currentValue = -1e7 - 1;
		auto count = 0;
		auto i = 0, j = 0;
		
		while (i < nums.size() && j < numsAddtion.size())
		{
			if (nums[i] < numsAddtion[j])
				++i;
			else if (nums[i] > numsAddtion[j])
				++j;
			else
			{
				if (nums[i] != currentValue)
				{
					++count;
					currentValue = nums[i];
				}
				++i;
				++j;
			}
		}

		return count;
	}
};