/*


Excel Sheet Column Number 


Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

@author Zixuan
@date	2015/8/26
*/

#include <string>
using namespace std;
class Solution 
{
public:
    int titleToNumber(string s)
	{
		int sum = 0;
		int exp = 1;//26^0.

		int length = (int)s.length();
		for (--length; length >= 0; --length)
		{
			int base = s[length] - 'A' + 1;
			sum += base * exp;
			exp *= 26;
		}

		return sum;

    }
};
