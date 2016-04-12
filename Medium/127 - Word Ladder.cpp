/*


Word Ladder


Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
1.Only one letter can be changed at a time
2.Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]


As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

@author Zixuan
@date	2016/4/12
*/

#include <unordered_set>
#include <set>
#include <queue>
using namespace std;

class Solution 
{
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
	{
		//Use BFS: The length of path from beginWord to endWord, with graph constructed from wordList.
		//Reference: https://leetcode.com/discuss/42006/easy-76ms-c-solution-using-bfs.
		auto length = 2;

		//Use set to accelerate instead of unordered_set.
		set<string> list;
		for (auto element : wordList)
			list.insert(element);

		queue<string> wordQueue;//Used in BFS.

		addWordsToQueue(beginWord, wordQueue, list);

		while (!wordQueue.empty())
		{	
			auto num = wordQueue.size();
			for (auto i = 0; i < num; ++i) 
			{
				auto word = wordQueue.front();
				wordQueue.pop();

				if (word == endWord) 
					return length;

				addWordsToQueue(word, wordQueue, list);
			}
			length++;
		}

		return 0;
	}

private:
	void addWordsToQueue(string word, queue<string>& wordQueue, set<string>& list)
	{
		list.erase(word);

		for (auto p = 0; p < word.length(); ++p) 
		{
			auto letter = word[p];
			for (auto k = 0; k < 26; ++k) 
			{
				word[p] = 'a' + k;
				if (list.find(word) != list.end()) //Found.
				{
					wordQueue.push(word);
					list.erase(word);
				}
			}
			word[p] = letter;//Change back.
		}

	}
};
