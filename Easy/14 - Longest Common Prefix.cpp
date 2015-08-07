/*


Longest Common Prefix


Write a function to find the longest common prefix string amongst an array of strings.

@author Zixuan
@date	2015/8/7
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		//sort(strs.begin(), strs.end());//Makes no sense.

		if (0 == strs.size())
			return "";

		string possibleStr(strs[0]);
		int validLength = possibleStr.length();

		for (int i = 1; i < strs.size(); ++i)
		{
			int j = 0;
			for (j = 0; strs[i][j] && j < validLength; ++j)
				if (possibleStr[j] != strs[i][j])
					break;

			if (0 == j)
				return "";

			validLength = j;
		}

		string retString = possibleStr.substr(0, validLength);
		return retString;
	}
};

