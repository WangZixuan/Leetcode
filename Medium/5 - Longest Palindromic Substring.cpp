/*


Longest Palindromic Substring


Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

@author Zixuan
@date	2015/9/7
*/

#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:

	//Use DP.
	//See http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

	string longestPalindrome(string s)
	{
		int length = s.length();

		bool isPalindrom[1000][1000];
		for (unsigned int i = 0; i < 1000; ++i)
			for (unsigned int j = 0; j < 1000; ++j)
				isPalindrom[i][j] = false;

		//ATTENTION: If we use 'new'&'delete', it causes 'Memory Limit Exceeded'.
		/*
		bool** isPalindrom = new bool*[length];
		for (int i = 0; i < length; ++i)
		isPalindrom[i] = new bool[length];
		*/
		int maxLength = 1;
		//All substrings of length 1 are palindromes.
		for (int i = 0; i < length; ++i)
			isPalindrom[i][i] = true;

		//Check for sub-string of length 2.
		int start = 0;
		for (int i = 0; i < length - 1; ++i)
			if (s[i] == s[i + 1])
			{
				isPalindrom[i][i + 1] = true;
				start = i;
				maxLength = 2;
			}

		//Check for lengths greater than 2. 
		//Here k is length of substring.
		for (int k = 3; k <= length; ++k)
		{
			//Fix the starting index.
			for (int i = 0; i < length - k + 1; ++i)
			{
				//Get the ending index of substring from starting index i and length k
				int j = i + k - 1;

				//Checking for sub-string from ith index to jth index 
				//iff str[i+1] to str[j-1] is a palindrome.
				if (isPalindrom[i + 1][j - 1] && s[i] == s[j])
				{
					isPalindrom[i][j] = true;

					if (k > maxLength)
					{
						start = i;
						maxLength = k;
					}
				}
			}
		}


		//Delete
		/*
		for (int i = 0; i < length; ++i)
		delete[] isPalindrom[i];
		delete[] isPalindrom;
		*/
		return s.substr(start, maxLength);
	}



	//Says: Time Limit Exceeded 
	/*
	string longestPalindrome(string s)
	{
		string longestSubstr;

		for (int i = (int)s.length() - 1; i >= 0; --i)
		{
			size_t pos = s.find_first_of(s[i]);
			string temp = s.substr(pos, i - pos + 1);

			while (string::npos != pos)
			{
				if (isPalindrome(temp))
				{
					if (longestSubstr.length() < temp.length())
					longestSubstr = temp;
					break;
				}
				else
				{
					temp = temp.substr(1, string::npos);
					pos = temp.find_first_of(s[i]);
					temp = temp.substr(pos, string::npos);
				}
			}
		}

		return longestSubstr;
	}

	private:
	inline bool isPalindrome(string s)
	{
		string temp(s);
		reverse(temp.begin(), temp.end());
		return (0 == s.compare(temp));
	}
	*/
};
