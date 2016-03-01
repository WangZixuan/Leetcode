/*


Valid Anagram


Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

@author Zixuan
@date 2016/2/29
*/

class Solution 
{
public:
	bool isAnagram(string s, string t) 
	{
		if (s.length() != t.length())
			return false;

		int s_count[26] = { 0 };//Without braces, it won't be zero by default.
		int t_count[26] = { 0 };

		for (auto c : s)
			++s_count[c - 'a'];

		for (auto c : t)
			++t_count[c - 'a'];

		for (auto i = 0; i < 26; ++i)
			if (s_count[i] != t_count[i])
				return false;

		return true;

	}
};