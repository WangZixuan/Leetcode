/*


Bold Words in String


Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.
The returned string should use the least number of tags possible, and of course the tags should form a valid combination.
For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.
Note:
words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.

@author Zixuan
@date   2018/1/7
*/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string boldWords(vector<string>& words, string S)
	{
		string flag(S.length(), '0');

		for (auto word : words)
		{
			vector<unsigned> positions;
			findAllOccurances(positions, S, word);
			for (auto p : positions)
			{
				string allOne(word.length(), '1');
				flag.replace(p, word.length(), allOne);
			}

		}

		//Add tags.
		string::size_type pos = 0;
		unsigned SPos = 0;
		auto state = false;
		while (true)
		{
			pos = flag.find("1", pos);
			if (pos != string::npos)
			{
				S.insert(pos + SPos, "<b>");
				SPos += 3;
				state = true;
			}
			else
				break;
			pos = flag.find("0", pos);
			if (pos != string::npos)
			{
				S.insert(pos + SPos, "</b>");
				SPos += 4;
				state = false;
			}
			else
				break;

		}

		if (state)
			S += "</b>";

		return S;
	}

private:
	void findAllOccurances(vector<unsigned>& vec, string& data, string& toSearch)
	{
		auto pos = data.find(toSearch);
		while (pos != std::string::npos)
		{
			vec.push_back(pos);
			pos = data.find(toSearch, pos + 1);
		}
	}
};