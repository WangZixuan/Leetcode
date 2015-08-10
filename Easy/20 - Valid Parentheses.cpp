/*


Valid Parentheses


Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

@author Zixuan
@date	2015/8/10
*/

#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> strStack;
		for (char c : s)
		{
			if ('(' == c || '[' == c || '{' == c)
				strStack.push(c);
			else if (')' == c || ']' == c || '}' == c)
			{
				switch (c)
				{
				case ')':
					if (!strStack.empty() && '(' == strStack.top())
						strStack.pop();
					else
						return false;
					break;
				case ']':
					if (!strStack.empty() && '[' == strStack.top())
						strStack.pop();
					else
						return false;
					break;
				case '}':
					if (!strStack.empty() && '{' == strStack.top())
						strStack.pop();
					else
						return false;
					break;
				}
			}
			else
				return false;

		}

		if (strStack.empty())
			return true;
	}
};
