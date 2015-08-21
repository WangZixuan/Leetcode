/*


Valid Palindrome


Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 

@author Zixuan
@date	2015/8/21
*/

#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s) 
	{
		if (0 == s.length() || 1 == s.length())
			return true;
		int it1 = 0;
		int it2 = s.length() - 1;

		while (it1 <= it2)
		{
			if (!(isalnum(s[it1]) || isalpha(s[it1])))
			{
				++it1;
				continue;
			}

			if (!(isalnum(s[it2]) || isalpha(s[it2])))
			{
				--it2;
				continue;
			}
			
				
			if (tolower(s[it1]) == tolower(s[it2]))
			{
				++it1;
				--it2;
			}
			else
				return false;
		}

		return true;
    }
};
