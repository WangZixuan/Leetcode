/*


Complex Number Multiplication


Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
Example 1:
	Input: "1+1i", "1+1i"
	Output: "0+2i"
	Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
	Input: "1+-1i", "1+-1i"
	Output: "0+-2i"
	Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

Note:
	The input strings will not have extra blank.
	The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

@author Zixuan
@date	2017/9/14
*/

#include <string>
using namespace std;

class Solution 
{
public:
	string complexNumberMultiply(string a, string b)
	{
		auto aReal = 0, aComp = 0, bReal = 0, bComp = 0;

		//Split a
		auto it = a.find('+');
		aReal = stoi(a.substr(0, it));
		aComp = stoi(a.substr(it + 1, string::npos - 1));

		//Split b
		it = b.find('+');
		bReal = stoi(b.substr(0, it));
		bComp = stoi(b.substr(it + 1, string::npos - 1));

		//Multiply
		auto real = aReal*bReal - aComp*bComp;
		auto comp = aReal*bComp + bReal*aComp;

		return to_string(real) + "+" + to_string(comp) + "i";
	}
};
