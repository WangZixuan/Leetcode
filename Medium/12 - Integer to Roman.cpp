/*


Integer to Roman 


Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

@author Zixuan
@date	2015/9/8
*/

#include <string>
#include <map>
using namespace std;
class Solution 
{
public:
	string intToRoman(int num) 
	{
		//Init
		map<int, string> basics;

		basics.insert(make_pair(1, "I"));
		basics.insert(make_pair(2, "II"));
		basics.insert(make_pair(3, "III"));
		basics.insert(make_pair(4, "IV"));
		basics.insert(make_pair(5, "V"));
		basics.insert(make_pair(6, "VI"));
		basics.insert(make_pair(7, "VII"));
		basics.insert(make_pair(8, "VIII"));
		basics.insert(make_pair(9, "IX"));

		basics.insert(make_pair(10, "X"));
		basics.insert(make_pair(20, "XX"));
		basics.insert(make_pair(30, "XXX"));
		basics.insert(make_pair(40, "XL"));
		basics.insert(make_pair(50, "L"));
		basics.insert(make_pair(60, "LX"));
		basics.insert(make_pair(70, "LXX"));
		basics.insert(make_pair(80, "LXXX"));
		basics.insert(make_pair(90 ,"XC"));

		basics.insert(make_pair(100, "C"));
		basics.insert(make_pair(200, "CC"));
		basics.insert(make_pair(300, "CCC"));
		basics.insert(make_pair(400, "CD"));
		basics.insert(make_pair(500, "D"));
		basics.insert(make_pair(600, "DC"));
		basics.insert(make_pair(700, "DCC"));
		basics.insert(make_pair(800, "DCCC"));
		basics.insert(make_pair(900, "CM"));

		basics.insert(make_pair(1000, "M"));
		basics.insert(make_pair(2000, "MM"));
		basics.insert(make_pair(3000, "MMM"));

		//Start the string.
		string s = "";
		if (num / 1000 > 0)
		{
			auto pos = basics.find(num / 1000 * 1000);
			if (basics.end() != pos)
				s = pos->second;
		}
		num %= 1000;

		if (num / 100 > 0)
		{
			auto pos = basics.find(num / 100 * 100);
			if (basics.end() != pos)
				s += pos->second;
		}
		num %= 100;

		if (num / 10 > 0)
		{
			auto pos = basics.find(num / 10 * 10);
			if (basics.end() != pos)
				s += pos->second;
		}
		num %= 10;

		if (num  > 0)
		{
			auto pos = basics.find(num);
			if (basics.end() != pos)
				s += pos->second;
		}

		return s;
	}
};
