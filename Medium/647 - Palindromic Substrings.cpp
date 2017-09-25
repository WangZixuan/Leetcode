/*


Palindromic Substrings


Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
Example 1:
	Input: "abc"
	Output: 3
	Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
	Input: "aaa"
	Output: 6
	Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.

@author Zixuan
@date	2017/9/25
 */
#include <string>
using namespace std;

class Solution 
{
public:
	int countSubstrings(string s) 
	{
		auto count = 0;
		for (auto i = 0; i < s.length(); ++i)
			for (auto j = i; j < s.length();++j)
				if (isPalindromic(s, i, j))
					++count;
		return count;
	}

private:
	bool isPalindromic(const string& s, int start, int end) const
	{
		while (start < end)
		{
			if (s[start] != s[end])
				return false;
			++start;
			--end;
		}
		return true;
	}
};
