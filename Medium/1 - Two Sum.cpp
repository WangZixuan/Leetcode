/*


Two Sum 


Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

@author Zixuan
@date	2015/8/24
*/


#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> copyNums(nums);
		sort(nums.begin(), nums.end());

		vector<int> pairNums;

		//My very first try with lambda funtion.-_-||
		//for_each(nums.begin(), nums.end(), [&](int val){pairNums.push_back(target - val);});
		//Wrong... How to do this?

		for (auto num : nums)
			pairNums.push_back(target - num);

		//Assumption: Each input would have exactly one solution.
		for (int i = 0, j = pairNums.size() - 1; i < j;)//O(N).
		{
			if (nums[i] == pairNums[j])
			{
				vector<int> retVector;

				//Search nums[i] and nums[j] in copyNums;
				auto it = find(copyNums.begin(), copyNums.end(), nums[i]);
				retVector.push_back(it - copyNums.begin() + 1);//Index starts from 1.

				auto jt = find(it + 1, copyNums.end(), nums[j]);
				if (copyNums.end() == jt)
					jt = find(copyNums.begin(), jt, nums[j]);//Make sure they do not go together.
				retVector.push_back(jt - copyNums.begin() + 1);

				sort(retVector.begin(), retVector.end());

				return retVector;
			}
			else if (nums[i] < pairNums[j])
				++i;
			else//nums[i] > pairNums[j]
				--j;
		}

		//Should never come here.
		pairNums.clear();
		return pairNums;
    }
};
