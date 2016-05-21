/*


Ugly Number


Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

@author Zixuan
@date	2016/5/21
*/
class Solution 
{
public:
	bool isUgly(int num) 
	{
		if (0 == num)
			return false;
		if (1 == num)
			return true;

		while (1 != num)
		{
			if (0 == num % 2)
				num /= 2;
			else if (0 == num % 3)
				num /= 3;
			else if (0 == num % 5)
				num /= 5;
			else
				return false;
		}
		return true;
	}
};