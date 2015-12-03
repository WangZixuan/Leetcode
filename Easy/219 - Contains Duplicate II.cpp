/*


Contains Duplicate II


Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

@author Zixuan
@date	2015/12/3
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		if (0 == k)
			return false;
		else if (nums.size() - 1 <= k)
		{
			set<int> setOfNums(nums.begin(), nums.end());
			return setOfNums.size() != nums.size();
		}

		vector<int> subVec(nums.begin(), nums.begin() + k + 1);

		//O(nk)
		for (int i = 0; i < nums.size() - k; ++i)
		{
			for (int j = 1; j <= k; ++j)
			{
				if (subVec[0] == subVec[j])
					return true;
			}
			subVec.erase(subVec.begin());

			if (i + k + 1 < nums.size())
				subVec.push_back(nums[i + k + 1]);
		}

		//What remains...
		if (k > 1)
		{
			vector<int> numsLeft(nums.begin() + (nums.size() - k), nums.end());
			set<int> setOfNumsLeft(numsLeft.begin(), numsLeft.end());
			return numsLeft.size() != setOfNumsLeft.size();
		}
		else//They do not have remainings...
			return false;

	}
};
