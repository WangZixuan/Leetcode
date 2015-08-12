/*


Length of Last Word


Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

@author Zixuan
@date	2015/8/12
*/
#include <string>
using namespace std;
class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		string temp;
		string valid;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] != ' ')
			{
				temp += s[i];
				valid = temp;//Update valid.
			}
			else
				temp.clear();
		}
		return valid.length();
	}
};
