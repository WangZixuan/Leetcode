/*


Rotate Array 


Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].

Note:
	Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
	Could you do it in-place with O(1) extra space?

@author Zixuan
@date	2015/9/7
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	void rotate(vector<int>& nums, int k) 
	{
		//If we want to do it in-place, we could just rotate one element, for k times.
		//That will hurt us in time complexity.

		k = k % nums.size();
		if (0 == k)
			return;

		vector<int> temp;
		for (unsigned int i = 0; i < nums.size(); ++i)
			temp.push_back(nums[((int)nums.size() - k + i) % (int)nums.size()]);

		nums = temp;
		return;
	}
};

