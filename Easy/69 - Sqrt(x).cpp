/*


Sqrt(x)


Implement int sqrt(int x).
Compute and return the square root of x.

@author Zixuan
@date	2017/7/26
*/

class Solution 
{
public:
	int mySqrt(int x)
	{
		if (0 >= x)
			return 0;
		if (3 >= x)
			return 1;
		auto start = 2;
		auto end = x / 2;
		while (start < end)
		{
			auto middle = (start + end) / 2;
			
			auto quotient = x / middle;
			if (quotient == middle)//We do not compare the product with x because the product may be overflow.
				return middle;

			if (start == middle)
				break;

			if (quotient > middle)
				start = middle;
			else
				end = middle;
		}
		return start;
	}
};
