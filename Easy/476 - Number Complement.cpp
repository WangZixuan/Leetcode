/*


Number Complement


Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
Note:
	The given integer is guaranteed to fit within the range of a 32-bit signed integer.
	You could assume no leading zero bit in the integer¡¯s binary representation.

Example 1:
	Input: 5
	Output: 2
	Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
	Input: 1
	Output: 0
	Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

@author Zixuan
@date	2017/1/16
*/

#include <iostream>
using namespace std;

class Solution 
{
public:
	int findComplement(int num) 
	{
		auto temp = num;
		auto count = 0;
		while (0!=num)
		{
			++count;
			num >>= 1;
		}
		
		//When it comes to INT_MAX, you must be really careful.
		auto power = static_cast<long long>(pow(2, count));
		return power == temp ? temp - 1 : power - 1 - temp;
	}
};

int main()
{
	Solution s;
	cout << s.findComplement(2147483647);
	
	system("pause");
	return 0;
}