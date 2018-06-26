/*


Maximum Product Subarray


Example 1:
	Input: [2,3,-2,4]
	Output: 6
	Explanation: [2,3] has the largest product 6.

Example 2:
	Input: [-2,0,-1]
	Output: 0
	Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

@author Zixuan
@date	2018/6/26
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		auto maxSoFar = nums[0];
		auto product = 1;

		for (auto n : nums)
		{
			if (0 == n)
			{
				product = 1;
				maxSoFar = max(0, maxSoFar);
			}
			else
			{
				product *= n;
				maxSoFar = maxSoFar > product ? maxSoFar : product;
			}
		}

		//Reverse order
		product = 1;
		for (int i = nums.size() - 1; i > 0;--i)
		{
			auto n = nums[i];
			if (0 == n)
			{
				product = 1;
				maxSoFar = max(0, maxSoFar);
			}
			else
			{
				product *= n;
				maxSoFar = maxSoFar > product ? maxSoFar : product;
			}
		}
		return maxSoFar;
	}
};
