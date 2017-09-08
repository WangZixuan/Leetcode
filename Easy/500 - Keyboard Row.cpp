/*


Keyboard Row


Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.

@author Zixuan
@date	2017/9/8
*/

#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
	vector<string> findWords(vector<string>& words)
	{
		vector<string> result;

		for (auto& word : words)
		{
			auto r = row(word[0]);
			auto flag = true;

			for (unsigned i = 1; i < word.length(); ++i)
				if (r != row(word[i]))
				{
					flag = false;
					break;
				}

			if (flag)
				result.push_back(word);
		}

		return result;
	}

private:

	int row(char c)
	{
		if (first.find(c) != first.end())
			return 1;

		if (second.find(c) != second.end())
			return 2;

		return 3;
	}

	set<char> first{ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' };
	set<char> second{ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };
};
