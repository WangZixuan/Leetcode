/*


Number of Matching Subsequences


Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
	Example :
	Input:
	S = "abcde"
	words = ["a", "bb", "acd", "ace"]
	Output: 3
	Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:
	All words in words and S will only consists of lowercase letters.
	The length of S will be in the range of [1, 50000].
	The length of words will be in the range of [1, 5000].
	The length of words[i] will be in the range of [1, 50].

@author Zixuan
@date	2018/3/4
*/

#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	int numMatchingSubseq(string S, vector<string>& words) 
	{
		auto count = 0;
		set<string> isOK;
		for (auto& word:words)
		{
			if (isOK.find(word)!=isOK.end())
			{
				++count;
				continue;
			}

			//Compare word and S
			auto indexWord = 0;
			auto indexS = 0;

			auto flag = false;
			while (indexWord < word.length() && indexS < S.length())
			{
				if (word[indexWord] == S[indexS])
				{
					if (indexWord == word.length()-1)
					{
						flag = true;
						isOK.insert(word);
						break;
					}

					++indexWord;
					++indexS;
				}
				else
					++indexS;
			}

			if (flag)
				++count;
			
		}
		return count;
	}
};
