/*


First Unique Character in a String


Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Examples:
	s = "leetcode"
	return 0.

	s = "loveleetcode",
	return 2.

Note: You may assume the string contain only lowercase letters.

@author Zixuan
@date	2016/8/25
*/

#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
	int firstUniqChar(string s) 
	{
		vector<int> times;//Store how many times this char is.
		times.resize(26);//Only lowercase letters

		for (auto i = 0; i < s.length(); ++i)
			++times[s[i] - 'a'];

		for (auto i = 0; i < s.length(); ++i)
			if (1 == times[s[i] - 'a'])
				return i;
		return -1;
	}
};
