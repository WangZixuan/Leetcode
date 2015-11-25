/*


Isomorphic Strings


Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

@author Zixuan
@date	2015/11/25
*/
#include <iostream>
#include <map>
using namespace std;

class Solution 
{
public:
	bool isIsomorphic(string s, string t) 
	{
		if (s.size() != t.size())
			return false;
		map<char, char> sMatchT;
		map<char, char> tMatchS;

		for (unsigned int i = 0; i < s.size(); ++i)
		{
			auto search = sMatchT.find(s[i]);
			if (search != sMatchT.end()) //Found.
			{
				if (t[i] != search->second)
					return false;
			}
			else //Not Found.
				sMatchT[s[i]] = t[i];

			search = tMatchS.find(t[i]);
			if (search != tMatchS.end()) //Found.
			{
				if (s[i] != search->second)
					return false;
			}
			else //Not Found.
				tMatchS[t[i]] = s[i];
		}

		return true;

	}
};