/*


Valid Triangle Number


Given an array consists of non-negative integers, 
task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Note:
	The length of the given array won't exceed 1000.
	The integers in the given array are in the range of [0, 1000].

@author Zixuan
@date	2017/12/11
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
	int triangleNumber(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());

		auto count = 0;

		for (unsigned i = 0; i < nums.size(); ++i)
			for (auto j = i + 1; j < nums.size(); ++j)
				for (auto k = j + 1; k < nums.size(); ++k)
					if (nums[i] + nums[j] > nums[k])
						++count;
					else
						break;

		return count;
	}
};