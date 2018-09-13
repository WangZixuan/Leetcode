/*


Delete and Earn


Given an array nums of integers, you can perform operations on the array. 
In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1. 
You start with 0 points. Return the maximum number of points you can earn by applying such operations. 

Example 1:
	Input: nums = [3, 4, 2]
	Output: 6
	Explanation:
	Delete 4 to earn 4 points, consequently 3 is also deleted.
	Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
	Input: nums = [2, 2, 3, 3, 3, 4]
	Output: 9
	Explanation:
	Delete 3 to earn 3 points, deleting both 2's and the 4.
	Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
	9 total points are earned.

Note:
	The length of nums is at most 20000.
	Each element nums[i] is an integer in the range [1, 10000].

@author Zixuan
@date	2018/5/22
*/

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int deleteAndEarn(vector<int>& nums)
	{
		map<int, int> pair;
		for (auto n : nums)
			if (pair.find(n) == pair.end())
				pair.insert(make_pair(n, 1));
			else
				++pair[n];

		auto avoid = 0, use = 0, prev = -1;

		for (auto& p : pair)
		{
			auto m = max(avoid, use);
			if (p.first - 1 == prev)
			{
				use = p.first*p.second + avoid;
				avoid = m;
			}
			else
			{
				use = p.first*p.second + m;
				avoid = m;
			}
			prev = p.first;
		}

		return max(avoid, use);
	}


};