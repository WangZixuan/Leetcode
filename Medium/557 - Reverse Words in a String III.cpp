/*


Reverse Words in a String


Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

@author Zixuan
@date	2017/9/24
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	void reverseWords(string& s) 
	{
		//Remove the space in front and back.
		auto startIndex = 0;
		while (s[startIndex] == ' ')
			++startIndex;
		s = s.substr(startIndex);

		reverse(s.begin(), s.end());

		startIndex = 0;
		while (s[startIndex] == ' ')
			++startIndex;
		s = s.substr(startIndex);

		auto start = 0, end = 0;

		while (end < s.length())
		{
			//Find space.
			if (s[end] == ' ')
			{
				//Reverse
				auto tempStart = start;
				auto tempEnd = end - 1;

				while (tempStart < tempEnd)
				{
					auto temp = s[tempStart];
					s[tempStart] = s[tempEnd];
					s[tempEnd] = temp;
					++tempStart;
					--tempEnd;
				}

				start = ++end;

			}
			else
				++end;

		}

		//Last word

		--end;
		while (start < end)
		{
			auto temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			++start;
			--end;
		}


		//If the string contains continuous space
		//Reference: https://stackoverflow.com/questions/8362094/replace-multiple-spaces-with-one-space-in-a-string
		auto new_end = unique(s.begin(), s.end(), bothAreSpaces);
		s.erase(new_end, s.end());
		
	}

private:
	static bool bothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

};
