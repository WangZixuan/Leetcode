/*


Ransom Note


Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.
Note:
	You may assume that both strings contain only lowercase letters.
	
	canConstruct("a", "b") -> false
	canConstruct("aa", "ab") -> false
	canConstruct("aa", "aab") -> true

@author Zixuan
@date	2016/8/21
*/

#include <string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) 
	{
		//IMPORTANT!
		//What if string is null/empty?
		if (0 == ransomNote.length())
			return true;

		while (true)
		{
			auto findPosition = magazine.find(ransomNote[0]);
			if (0 == magazine.length() ||string::npos == findPosition)
				return false;

			if (1 == ransomNote.length())
				return true;

			ransomNote = ransomNote.substr(1);
			magazine = magazine.substr(0, findPosition) + magazine.substr(findPosition + 1);
		}
	}
};
