/*


Next Greater Element II


Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, output -1 for this number.
Example 1:
	Input: [1,2,1]
	Output: [2,-1,2]
	Explanation: The first 1's next greater number is 2;
	The number 2 can't find next greater number;
	The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000.

@author Zixuan
@date	2017/3/23
*/

#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
	//218 / 224 test cases passed.
	//Time Limit Exceeded
	vector<int> nextGreaterElements1(vector<int>& nums) 
	{
		if (nums.size() <= 1)
		{
			vector<int> temp(nums.size(), -1);
			return temp;
		}
			
		auto full(nums);
		full.insert(full.end(), nums.begin(), nums.end());

		auto lastPos = 0;
		vector<int> result(nums.size(), INT_MIN);
		for (auto i = 0; i < full.size(); ++i)
		{
			auto meetGreaterEqual = false;
			auto j = lastPos;
			for (; j <= i && j < nums.size(); ++j)
			{
				if (full[i] > full[j] && INT_MIN == result[j])
				{
					result[j] = full[i];
					
					if (!meetGreaterEqual)
						lastPos++;
				}
				else
					meetGreaterEqual = true;
			}

		}

		for (auto& i : result)
			if (INT_MIN == i)
				i = -1;

		return result;
	}

	//https://discuss.leetcode.com/topic/77923/java-10-lines-and-c-12-lines-linear-time-complexity-o-n-with-explanation
	vector<int> nextGreaterElements(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> next(n, -1);
		stack<int> s; 

		for (auto i = 0; i < 2 * n; ++i)
		{
			auto num = nums[i % n];
			while (!s.empty() && nums[s.top()] < num)
			{
				next[s.top()] = num;
				s.pop();
			}
			if (i < n) 
				s.push(i);

		}
		
		return next;

	}
};