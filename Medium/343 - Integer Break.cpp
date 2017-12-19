/*


Integer Break


Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
Note: You may assume that n is not less than 2 and not larger than 58.

@author Zixuan
@date 2017/12/19
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int integerBreak(int n)
	{
		vector<int> integerBreaks(59, 1);
		integerBreaks[3] = 2;

		for (auto i = 3; i <= n; ++i)
		{
			auto maxValue = 1;

			for (auto j = 1; j <= i / 2; ++j)
			{
				auto p = i - j;
				auto maxSoFar = maxOfFour(j * p, j * integerBreaks[p], integerBreaks[j] * p, integerBreaks[j] * integerBreaks[p]);
				if (maxSoFar > maxValue)
					maxValue = maxSoFar;
			}
			integerBreaks[i] = maxValue;
			if (i == n)
				return maxValue;
		}


		return 1;//Never here.
	}

private:
	int maxOfFour(int i1, int i2, int i3, int i4)
	{
		return max(max(max(i1, i2), i3), i4);
	}
};
