/*


3Sum


Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = { -1, 0, 1, 2, -1, -4 },

A solution set is :
(-1, 0, 1)
(-1, -1, 2)

@author Zixuan
@date	2016/7/6
*/
//I came to this problem on 2015/9/8...

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> result;

		sort(nums.begin(), nums.end());

		auto fixedValue = INT_MIN;
		for (auto i = 0; i < nums.size(); ++i)
		{
			if (fixedValue == nums[i])
				continue;

			fixedValue = nums[i];

			vector<int> pairNums;
			for (auto j = i + 1; j < nums.size(); ++j)
				pairNums.push_back(-fixedValue - nums[j]);

			//Next we check if nums[i+1...end] and pairNums are pairs.
			for (auto j = i + 1, k = static_cast<int>(pairNums.size()) - 1; j < k + i + 1;)
			{
				auto first = nums[j];
				auto second = pairNums[k];
				if (first == second)
				{
					vector<int> temp{ fixedValue, first, nums[k + i + 1] };
					result.push_back(temp);
					++j; --k;

					//Remove duplicates of first.
					while (j < k + i + 1 && first == nums[j]) ++j;

					//Remove duplicates of second.
					while (j < k + i + 1 && second == pairNums[k]) --k;
				}
				else if (first < second)
					++j;
				else
					--k;
			}
		}

		return result;
	}

};
