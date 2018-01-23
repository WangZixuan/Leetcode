/*


Reorganize String


Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
If possible, output any possible result.  If not possible, return the empty string.
Example 1:
	Input: S = "aab"
	Output: "aba"
Example 2:
	Input: S = "aaab"
	Output: ""
Note:
S will consist of lowercase letters and have length in range [1, 500].

@author Zixuan
@date	2018/1/23
*/

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct LetterCount
{
	char c;
	int count;
	LetterCount(char c, int count) :c(c), count(count){}
	
	bool operator < (const LetterCount& other) const
	{
		return count < other.count;
	}
};
class Solution 
{
public:
	string reorganizeString(string S) 
	{
		vector<int> count(26, 0);
		for (auto c : S)
			++count[c - 'a'];
		vector<LetterCount> letter_counts;
		for (auto i = 0; i < count.size(); ++i)
			if (0 != count[i])
			{
				LetterCount lc('a' + i, count[i]);
				letter_counts.push_back(lc);
			}

		make_heap(letter_counts.begin(), letter_counts.end());

		auto frontCountLetter = letter_counts.front();
		if (frontCountLetter.count > (S.length() + 1) / 2)
			return "";

		//Use heap.
		//Pay attention to heap usage.
		string result = "";
		while (letter_counts.size() > 1)
		{
			auto maxCountLetter = letter_counts.front();
			pop_heap(letter_counts.begin(), letter_counts.end());
			letter_counts.pop_back();
			auto secondMaxCountLetter = letter_counts.front();
			pop_heap(letter_counts.begin(), letter_counts.end());
			letter_counts.pop_back();

			auto pair = string(1, maxCountLetter.c) + string(1, secondMaxCountLetter.c);

			maxCountLetter.count -= secondMaxCountLetter.count;
			while (secondMaxCountLetter.count > 0)
			{
				result += pair;
				--secondMaxCountLetter.count;
			}

			if (maxCountLetter.count > 0)
			{
				letter_counts.push_back(maxCountLetter);
				push_heap(letter_counts.begin(), letter_counts.end());
			}
			else
			{
				secondMaxCountLetter.count = 1;
				result = result.substr(0, result.length() - 1);
				letter_counts.push_back(secondMaxCountLetter);
				push_heap(letter_counts.begin(), letter_counts.end());
			}

		}

		if (letter_counts.size() == 1)
			result += letter_counts[0].c;

		return result;
	}
};
