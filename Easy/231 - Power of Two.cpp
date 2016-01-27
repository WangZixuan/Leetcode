/*


Power of Two


Given an integer, write a function to determine if it is a power of two.

@author Zixuan
@date	2016/1/27
*/

class Solution 
{
public:
	bool isPowerOfTwo(int n) 
	{
		if (0 >= n)
			return false;

		if (1 == n)
			return true;

		while (1 != n)
		{
			if (1 == n % 2)
				return false;

			n >>= 1;
		}

		return true;
	}
};