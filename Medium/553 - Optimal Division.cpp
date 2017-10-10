/*


Optimal Division


Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.
However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, 
and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.
Example:
	Input: [1000,100,10,2]
	Output: "1000/(100/10/2)"
	Explanation:
	1000/(100/10/2) = 1000/((100/10)/2) = 200
	However, the bold parenthesis in "1000/((100/10)/2)" are redundant,
	since they don't influence the operation priority. So you should return "1000/(100/10/2)".

	Other cases:
	1000/(100/10)/2 = 50
	1000/(100/(10/2)) = 50
	1000/100/10/2 = 0.5
	1000/100/(10/2) = 2

Note:
The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.

@author Zixuan
@date	2017/10/10
*/

#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
	//The answer to a/b/c/d/e/f will be a/(b/c/d/e/f)
	//Reference: https://leetcode.com/problems/optimal-division/solution/
	string optimalDivision(vector<int>& nums) 
	{
		if (1 == nums.size())
			return to_string(nums[0]);

		if (2 == nums.size())
			return to_string(nums[0]) + "/" + to_string(nums[1]);

		string division;
		division += to_string(nums[0]) + "/(";

		for (auto i = 1; i < nums.size() - 1; ++i)
			division += to_string(nums[i]) + "/";

		division += to_string(nums.back()) + ")";
		return division;
	}
};
