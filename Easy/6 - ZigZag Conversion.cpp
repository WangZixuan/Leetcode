/*


ZigZag Conversion


The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

@author Zixuan
@date	2015/8/5
*/

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
	string convert(string s, int numRows)
	{
		int length = s.length();
		int loop = 2 * numRows - 2;

		string* arr = new string[numRows];

		for (int i = 0; i < length; ++i)
		{
			int temp = (0 == loop) ? 0 : i % loop;
			if (temp <= numRows - 1)
				arr[temp] += s[i];
			else
				arr[loop - temp] += s[i];
		}

		//Join
		string retString;
		for (int i = 0; i < numRows; ++i)
			retString.append(arr[i]);

		return retString;
	}
};
