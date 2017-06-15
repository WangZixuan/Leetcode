/*


Maximum Subarray


Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
click to show more practice.
More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

@author Zixuan
@date	2017/5/25
*/


#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		return maxOfTotal(nums, 0, nums.size() - 1);
	}

private:

	int maxOfTotal(vector<int>& nums, int start, int end)
	{
		if (start == end)
			return nums[start];

		auto mid = (start + end) / 2;
		auto first = maxOfTotal(nums, start, mid);
		auto second = maxOfTotal(nums, mid+1, end);

		return maxOfThree(first, second, maxIncludeThis(nums, start, end, mid));
	}

	int maxIncludeThis(vector<int>& nums, int start, int end, int mid)
	{
		auto sum = 0;
		auto left_sum = INT_MIN;
		for (auto i = mid; i >= start; i--)
		{
			sum = sum + nums[i];
			if (sum > left_sum)
				left_sum = sum;
		}

		// Include elements on right of mid
		sum = 0;
		auto right_sum = INT_MIN;
		for (auto i = mid + 1; i <= end; i++)
		{
			sum = sum + nums[i];
			if (sum > right_sum)
				right_sum = sum;
		}

		// Return sum of elements on left and right of mid
		return left_sum + right_sum;
	}

	int maxOfThree(int a, int b, int c) const
	{
		return max(max(a, b), c);
	}
};
