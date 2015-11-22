/*


Happy Number


Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.


@author Zixuan
@date	2015/11/22
*/

class Solution 
{
public:
	bool isHappy(int n) 
	{
		set<int> numbers;
		numbers.insert(n);

		while (true)
		{
			int temp = 0;
			while (0 != n)
			{
				temp += (n % 10)*(n % 10);
				n /= 10;
			}

			if (1 == numbers.count(temp) && 1 != temp)
				return false;
			else if (1 == numbers.count(temp) && 1 == temp)
				return true;

			numbers.insert(temp);
			n = temp;
		}
		
		return true;
	}
};