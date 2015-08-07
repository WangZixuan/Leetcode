/*


Palindrome Number


Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

@author Zixuan
@date	2015/8/7
*/

#include <cmath>

class Solution
{
public:
	bool isPalindrome(int x)
	{
		//Is my solution so-called "without extra space"?

		long long temp = x;
		if (temp < 0 || temp >= INT_MAX )
			return false;

		//All negative num is false!!! 
		//Reference: https://leetcode.com/discuss/10458/2147447412-is-not-a-palindromic-number
		//What if x = -0?
		//x = (x >= 0) ? (int)x : (int)-x;

		//Get digit.
		int xCopy = x;
		int digit = 0;
		while (xCopy > 0)
		{
			++digit;
			xCopy /= 10;
		}

		//If x = 0.
		digit = (0 == x) ? 1 : digit;

		xCopy = x;
		int compareTime = digit / 2;//Consider it odd or even.

		for (int i = 0; i < compareTime; ++i)
		{
			int highTens = (int)pow(10, digit - i - 1);
			if (xCopy % 10 == x / highTens)
			{
				xCopy /= 10;
				x %= highTens;
			}
			else
				return false;
		}
		return true;
	}
};

