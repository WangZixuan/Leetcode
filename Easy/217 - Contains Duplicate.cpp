/*


Contains Duplicate


Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


@author Zixuan
@date	2015/12/1
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution 
{
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		set<int> setOfNums(nums.begin(), nums.end());

		return !(setOfNums.size() == nums.size());
	}
};
