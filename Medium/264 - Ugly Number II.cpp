/*


Ugly Number II


Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

@author Zixuan
@date	2017/12/12
*/

#include <algorithm>
#include <vector>
using namespace std;
class Solution 
{
public:
	//Reference: https://discuss.leetcode.com/topic/24306/elegant-c-solution-o-n-space-time-with-detailed-explanation
	int nthUglyNumber(int n) 
	{
		vector<int> results{ 1 };
		auto i = 0, j = 0, k = 0;
		while (results.size() < n)
		{
			auto next = min(results[i] * 2, min(results[j] * 3, results[k] * 5));
			results.push_back(next);
			if (next == results[i] * 2)
				++i;
			if (next == results[j] * 3)
				++j;
			if (next == results[k] * 5)
				++k;
		}
		return results.back();

	}
};
