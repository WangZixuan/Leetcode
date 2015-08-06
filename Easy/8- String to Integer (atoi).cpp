/*


String to Integer (atoi)


Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

@author Zixuan
@date	2015/8/6
*/

#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
	int myAtoi(string str)
	{
		int startPos = 0;
		while (str[startPos] == ' ' || str[startPos] == '\t' || str[startPos] == '\n' || str[startPos] == '\r')
			++startPos;

		bool flag = true;

		//Is it minus, plus, digit or something else?
		if (str[startPos] == '-')
		{
			flag = false;
			++startPos;
		}
		else if (str[startPos] == '+')
		{
			flag = true;
			++startPos;
		}
		else if (!(str[startPos] <= '9' && str[startPos] >= '0'))
			return 0;

		if (!(str[startPos] <= '9' && str[startPos] >= '0'))
			return 0;
		//Get startPos now.

		//Get length.
		int length = 1;
		while (str[startPos + length] <= '9' && str[startPos + length] >= '0')
			++length;


		string usefulStr = str.substr(startPos, length);

		//Weak restriction.
		if (length > 10 || (10 == length && flag && usefulStr.compare("2147483647") > 0) || (10 == length && !flag && usefulStr.compare("2147483648") > 0))
			return flag ? INT_MAX : INT_MIN;

		//Convert usefulStr to integer.
		int retInteger = 0;
		for (int i = 0; i < length; ++i)
			retInteger += (int)pow(10, i) * (usefulStr[length - i - 1] - '0');

		return flag ? retInteger : -retInteger;
	}
};
