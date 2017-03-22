/*


Reverse String II


Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:
	Input: s = "abcdefg", k = 2
	Output: "bacdfeg"

Restrictions:
	The string consists of lower English letters only.
	Length of the given string and k will in the range [1, 10000]

@author Zixuan
@date	2017/3/22
*/
#include <string>

using namespace std;

class Solution 
{
public:
	string reverseStr(string s, int k) 
	{
		if (0 == s.length() || 0 >= k)
			return s;

		string reversed;
		auto i = 0;
		while (i < s.length())
		{
			if (i + k <= s.length())
			{
				auto temp = s.substr(i, k);
				reverse(temp.begin(), temp.end());
				reversed += temp;

				if (i + 2 * k < s.length())
				{
					reversed += s.substr(i + k, k);
					i += 2 * k;
				}
				else
				{
					reversed += s.substr(i + k);
					break;
				}
			}
			else
			{
				auto temp = s.substr(i);
				reverse(temp.begin(), temp.end());
				reversed += temp;
				break;
			}
		}
		return reversed;
	}

};

int main()
{
	Solution s;
	s.reverseStr("abcd", 5);
}