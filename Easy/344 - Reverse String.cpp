/*


Reverse String


Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

@author Zixuan
@date	2016/6/5
*/

#include <string>
using namespace std;
class Solution 
{
public:
	string reverseString(string s) 
	{
		reverse(s.begin(), s.end());
		return s;
	}
};
