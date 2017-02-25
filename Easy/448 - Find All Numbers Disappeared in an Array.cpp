/*


Find All Numbers Disappeared in an Array


Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
	Input:
	[4,3,2,7,8,2,3,1]

	Output:
	[5,6]

@author Zixuan
@date	2017/02/25
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	//Reference: https://discuss.leetcode.com/topic/65738/java-accepted-simple-solution
	vector<int> findDisappearedNumbers(vector<int>& nums) 
	{
		vector<int> result;

		//We alter the original vector which will store some information.
		for (auto i = 0; i < nums.size(); ++i) 
		{
			auto val = abs(nums[i]) - 1;
			if (nums[val] > 0) 
				nums[val] = -nums[val];
		}

		for (auto i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > 0) 
				result.push_back(i + 1);
		}
		return result;
	}
};
	
int main()
{

	Solution s;
	vector<int> p{4, 3, 2, 2, 8, 2, 3, 1};
	s.findDisappearedNumbers(p);
	system("pause");

	return 0;
}