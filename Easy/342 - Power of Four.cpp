/*


Power of Four


Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?

@author Zixuan
@date	2016/5/31
*/

class Solution
{
public:
	//Failed without loop.
	bool isPowerOfFour(int num) 
	{
		if (0 >= num)
			return false;
		
		while (1 != num)
		{
			if (0 == num % 4)
				num >>= 2;
			else
				return false;
		}

		return true;
	}
};
