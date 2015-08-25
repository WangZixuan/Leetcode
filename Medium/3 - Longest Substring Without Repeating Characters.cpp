/*


Longest Substring Without Repeating Characters 


Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

@author Zixuan
@date	2015/8/25
*/

#include <string>
using namespace std;
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
	{
		/*
		My idea:
		Each character points to the nearest same character to form a cycle.
		Then we find the largest simple(Means no cycle inside) cycle.
		BUG: Cannot deal with cycle inside cycle...
		*/
		/*
		vector<int> v;//The index of previous same character that this element points to.
		map<char, int> m;//The index of the character it appeared recently.

		for (unsigned int i = 0; i < s.length(); ++i)
			if (m.end() != m.find(s[i]))//Found
			{
				v.push_back(m[s[i]]);
				m[s[i]] = i;
			}
			else
			{
				v.push_back(-1);
				m.insert(make_pair(s[i], i));
			}

		if (m.size() == s.length())
			return s.length();//Not neccessary.

		int maxCycle = INT_MIN;
		for (int i = 0; i < (int)v.size(); ++i)
			if (maxCycle < i - v[i])
				maxCycle = i - v[i];

		return maxCycle;
		*/

		/*Another idea:
		Iterate once, record the max length.
		Similar to maxSubstr in Algorithm class.
		This is smart and great!
		*/
		int maxLength = 0;
		string longestSubstr;

		for (int i = 0; i < (int)s.length(); ++i)
		{
			size_t pos = longestSubstr.find(s[i]);
			if (string::npos != pos)
				longestSubstr = longestSubstr.substr(pos + 1);
				
			longestSubstr += s[i];

			if (maxLength < (int)longestSubstr.size())
				maxLength = (int)longestSubstr.size();
			
		}

		return maxLength;
    }
};
