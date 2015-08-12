/*

Add Binary


Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

@author Zixuan
@date	2015/8/12
*/

#include <string>
using namespace std;
class Solution 
{
public:
    string addBinary(string a, string b) 
	{
		if ("" == a || "" == b)
			return ("" == a) ? b : a;

		//Make a the longer one.
		if (a.length() < b.length())
		{
			string temp = a;
			a = b; 
			b = temp;
		}

		string temp;
		for (int i = 0; i < a.length() - b.length(); ++i)
			temp += "0";

		b = temp + b;
		//Here a and b have the same length.

		//Reuse temp to reduce space occupied.
		temp.clear();

		int carry = 0;
		for(int i = a.length() - 1; i  >= 0; --i)
		{
			int value = (a[i] - '0') + (b[i] - '0') + carry;
		
			//Set its bit and carry.
			temp = (char)(value % 2 + '0') + temp;
			carry = value / 2;
		}

		if (carry)
			temp = "1" + temp;

		return temp;
	}
};
