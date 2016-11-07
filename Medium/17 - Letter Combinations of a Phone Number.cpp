/*


Letter Combinations of a Phone Number


Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

<img src="http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png">

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

@author Zixuan
@date	2016/11/7
*/

#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> result;
		if (0 == digits.size() || digits.find("1") != string::npos)
			return result;

		return append(result, digits);
	}

private:
	vector<string> buttons{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	vector<string> append(vector<string> last, string digits)
	{
		auto letters = buttons[digits[0] - '0' - 2];

		vector<string> present;
		if (0 != last.size())
			for (auto s : last)
			{
				auto length = letters.length();
				for (auto i = 0; i < length; ++i)
					present.push_back(s + letters[i]);
			}
		else
		{
			auto length = letters.length();
			for (auto i = 0; i < length; ++i)
				present.push_back(string(1, letters[i]));
		}

		digits = digits.substr(1);

		if (0 == digits.length())
			return present;
		return append(present, digits);
	}
};
