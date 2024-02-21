/*


Implement Trie (Prefix Tree)


A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True


Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

@author Zixuan
@date	2024/2/21
*/

#include <map>
#include <string>
using namespace std;

struct Node
{
	char c;
	bool isLeaf;
	map<char, Node*> indexes;

	explicit Node(char i)
	{
		c = i;
		isLeaf = false;
	}
};

class Trie
{
public:
	/** Initialize your data structure here. */
	Trie()
	{
		root = new Node('0');
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		auto x = root;

		for (auto c : word)
		{
			auto location = x->indexes.find(c);
			if (location == x->indexes.end())
			{
				x = x->indexes.insert({ c, new Node(c) }).first->second;
			}
			else
				x = location->second;
		}

		x->isLeaf = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		auto x = root;

		for (auto c : word)
		{
			auto location = x->indexes.find(c);
			if (location == x->indexes.end())
				return false;
			else
				x = location->second;
		}

		return x->isLeaf;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		auto x = root;

		for (auto c : prefix)
		{
			auto location = x->indexes.find(c);
			if (location == x->indexes.end())
				return false;
			else
				x = location->second;
		}

		return true;
	}

private:
	Node* root;
};
