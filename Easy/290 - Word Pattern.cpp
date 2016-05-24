/*


Word Pattern


Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

1.pattern = "abba", str = "dog cat cat dog" should return true.
2.pattern = "abba", str = "dog cat cat fish" should return false.
3.pattern = "aaaa", str = "dog cat cat dog" should return false.
4.pattern = "abba", str = "dog dog dog dog" should return false.

@author Zixuan
@date	2016/5/24
*/

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <set>

class Solution 
{
public:
	bool wordPattern(std::string pattern, std::string str) 
	{
		std::vector<std::string> each_word;
		std::istringstream iss(str);

		//Split string by a space.
		//Reference: http://stackoverflow.com/questions/236129/split-a-string-in-c
		do
		{
			std::string sub;
			iss >> sub;
			each_word.push_back(sub);

		} while (iss);
		each_word.pop_back();

		if (pattern.length() != each_word.size())
			return false;

		std::map<char, std::string> char_word;
		for (auto i = 0; i < pattern.length(); ++i)
		{
			auto c = pattern[i];
			if (char_word.find(c) == char_word.end())//Not found.
				char_word.insert(std::make_pair(c, each_word[i]));
			else
				if (char_word.at(c) != each_word[i])
					return false;
		}

		//If duplicated values, return false.
		//Without this, "abba" "dog dog dog dog" will be wrong.
		std::set<std::string> all_values;
		
		for (auto it = char_word.begin(); it != char_word.end(); ++it)
			all_values.insert(it->second);
			
		return all_values.size() == char_word.size();

	}
};

