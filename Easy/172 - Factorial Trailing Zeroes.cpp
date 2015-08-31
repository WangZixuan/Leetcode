/*


Factorial Trailing Zeroes 


Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

@author Zixuan
@date	2015/8/31
*/

#include <cmath>
class Solution 
{
public:
	int trailingZeroes(int n)
	{
		int numOfZeroes = 0;

		//It counts the number of 5.
		if (4 >= n)
			return 0;

		int exp = (int)(log(n) / log(5));
		int exponential = (int)pow(5, exp);

		for (int i = 1; i <= exp; ++i, exponential /= 5)
			numOfZeroes += (n / exponential);

		return numOfZeroes;
	}
};
