/*


Largest Palindrome Product


Find the largest palindrome made from the product of two n-digit numbers.
Since the result could be very large, you should return the largest palindrome mod 1337.
Example:
	Input: 2
	Output: 987
	Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

@author Zixuan
@date 2017/10/11
*/
#include <cmath>
#include <string>
using namespace std;

//Reference: https://discuss.leetcode.com/topic/74659/concise-c-solution
class Solution 
{
public:
	int largestPalindrome(int n) 
	{
		if (1 == n)
			return 9;

		auto down = static_cast<int>(pow(10, n-1));
		auto up = static_cast<int>(pow(10, n)) - 1;

		for (auto i = up; i >= down; --i)
		{
			auto cand = buildPalindrome(i);
			for (long j = up; j*j >= cand; --j)
			{
				if (cand % j == 0 && cand / j <= up)
					return cand % 1337;
			}
		}
		return 0;
	}

private:
	long buildPalindrome(int n) const
	{
		auto s = to_string(n);
		reverse(s.begin(), s.end());
		return stol(to_string(n) + s);
	}
};
