/*


Nth Digit


Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).
Example 1:
	Input:
	3

	Output:
	3

Example 2:
	Input:
	11

	Output:
	0

	Explanation:
	The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

@author Zixuan
@date 2017/10/9
*/
#include <cmath>

class Solution 
{
public:
	int findNthDigit(int n)
	{
		auto digits = 1;

		auto nTemp = n;
		while (n > 0)
		{
			nTemp = n;
			n -= digits * 9 * pow(10, digits - 1);
			++digits;
		}
		--digits;

		//Location.
		auto index = (nTemp - 1) / digits;
		auto i = digits - 1 - (nTemp - 1) % digits;

		//Get number
		auto number = static_cast<int>(pow(10, digits - 1)) + index;

		while (i-- > 0)
			number /= 10;

		return number % 10;

	}
};

int main()
{
	Solution s;
	s.findNthDigit(10);
}