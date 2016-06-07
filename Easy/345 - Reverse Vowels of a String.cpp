/*


Reverse Vowels of a String


Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

@author Zixuan
@date	2016/6/7
*/
#include <set>
using namespace std;
class Solution 
{
public:
	string reverseVowels(string s) 
	{
		set<char> vowels{ 'a','e','i','o','u','A','E','I','O','U' };//Do not forget upper class.
		auto first = 0;
		auto last = static_cast<int>(s.length()) - 1;//Without static cast, last will be unsigned int,
													 //which means that if s.length=0, last would not be -1.

		while (first < last)
		{
			while (vowels.end() == vowels.find(s[first]))
				++first;

			while (vowels.end() == vowels.find(s[last]))
				--last;

			if (first < last)
			{
				//Swap.
				auto temp = s[first];
				s[first] = s[last];
				s[last] = temp;

				++first;
				--last;
			}
		}

		return s;
	}
};
