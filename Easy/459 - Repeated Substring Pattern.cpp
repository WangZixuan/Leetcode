/*


Repeated Substring Pattern


Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
	Input: "abab"
	Output: True
	Explanation: It's the substring "ab" twice.

Example 2:
	Input: "aba"
	Output: False

Example 3:
	Input: "abcabcabcabc"
	Output: True
	Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

@author Zixuan
@date	2017/10/16
*/

#include <string>
using namespace std;
class Solution 
{
public:
	bool repeatedSubstringPattern(string s) 
	{
		auto length = s.length();

		for (auto subLength = 1; subLength <= length / 2; ++subLength)
		{
			if (0 != length%subLength)
				continue;

			auto pivotSubStr = s.substr(0, subLength);
			//Check
			auto flag = true;
			for (auto i = 1; i < length / subLength;++i)
			{
				auto nextSubStr = s.substr(i*subLength, subLength);
				if (0!=pivotSubStr.compare(nextSubStr))
				{
					flag = false;
					break;
				}
			}

			if (flag)
				return true;
		}
		return false;
	}
};
