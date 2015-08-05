/*


Reverse Integer


Reverse digits of an integer.

Example1: x = 123, return 321
Example2 : x = -123, return -321

Have you thought about this ?
Here are some good questions to ask before coding.Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow ? Assume the input is a 32 - bit integer, then the reverse of 1000000003 overflows.How should you handle such cases ?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

@author Zixuan
@date	2015/8/5
*/

#include <cmath>
#include <iostream>
using namespace std;
class Solution
{
public:
	int reverse(int x)
	{
		const bool flag = (x >= 0) ? true : false;
		x = (flag) ? x : -x;

		//Get digit of the integet.
		int xCopy = x;
		int digit = 0;
		while (xCopy > 0)
		{
			++digit;
			xCopy /= 10;
		}

		//A weak judgement.
		//Not a strict condition!
		if (digit >= 10 && x % 10 >= 3)
			return 0;

		int retInt = 0;
		xCopy = x;
		for (int i = 0; i < digit; ++i)
		{
			int value = (int)pow(10, digit - 1 - i) * (xCopy % 10);
			retInt += value;
			xCopy /= 10;
		}

		retInt = (flag) ? retInt : -retInt;

		if ((flag && retInt >= 0) || (!flag && retInt < 0))
			return retInt;
		else
			return 0;

	}
};
