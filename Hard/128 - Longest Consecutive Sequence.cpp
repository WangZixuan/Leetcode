/*


Longest Consecutive Sequence


Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

@author Zixuan
@date	2017/5/23
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//Reference: https://discuss.leetcode.com/topic/5333/possibly-shortest-cpp-solution-only-6-lines
//Great solution!
class Solution
{
public:
	int longestConsecutive(vector<int>& nums) 
	{
		unordered_map<int, int> m;
		auto r = 0;
		for (auto i : nums) 
		{
			if (m[i])
				continue;
			r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
		}
		return r;

	}
};
