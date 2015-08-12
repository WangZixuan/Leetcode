/*


Plus One


Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

@author Zixuan
@date	2015/8/12
*/

#include <vector>
using namespace std;

class Solution 
{
public: 
	vector<int> plusOne(vector<int>& digits) 
	{
	
		int backwardIndex = digits.size() - 1;
		if (-1 == backwardIndex)
			return digits;
	
		//Plus one.
		++digits[backwardIndex];

		//No carry.
		if (digits[backwardIndex] != 10)
			return digits;

		//If carry.
		while (true)
		{
			if (10 == digits[backwardIndex])
			{
				digits[backwardIndex] = 0;

				//Whether it goes to the most significant digit.
				if (backwardIndex > 0)
					++digits[backwardIndex - 1];
				else
				{
					vector<int>::iterator it = digits.begin();
					digits.insert(it, 1);
					return digits;
				}
			}
			else
				return digits;

			--backwardIndex;
		}


		return digits;//Suppose it never comes here...
	}
};

