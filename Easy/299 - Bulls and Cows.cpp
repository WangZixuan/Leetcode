/*


Bulls and Cows


You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") 
and how many digits match the secret number but locate in the wrong position (called "cows"). 
Your friend will use successive guesses and hints to eventually derive the secret number.

For example:
Secret number:  "1807"
Friend's guess: "7810"

Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:
Secret number:  "1123"
Friend's guess: "0111"

In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".

You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

@author Zixuan
@date	2016/5/26
*/

#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution 
{
public:
	string getHint(string secret, std::string guess) 
	{
		if (secret.length() != guess.length())
			return false;
		
		auto bull_count = 0;
		for (auto i = 0; i < secret.length(); ++i)
			if (secret[i] == guess[i])
			{
				++bull_count;
				secret[i] = guess[i] = ' ';//Remove it.
			}
		
		map<char, int> character_count_secret;
		characterCount(secret, character_count_secret);
		map<char, int> character_count_guess;
		characterCount(guess, character_count_guess);

		auto cow_count = 0;
		for (auto i = character_count_secret.begin(); i != character_count_secret.end(); ++i)
		{
			auto word = i->first;
			
			if (character_count_guess.find(word) != character_count_guess.end())//Found.
				cow_count += min(i->second, character_count_guess.find(word)->second);
		}


		return to_string(bull_count) + 'A' + to_string(cow_count) + 'B';
	}

private:
	void characterCount(string word, map<char, int>& character_count)
	{
		for (auto c : word)
			if (character_count.find(c) == character_count.end())//Not found.
				character_count.insert(make_pair(c, 1));
			else
			{
				auto temp = character_count.at(c);
				character_count.erase(character_count.find(c));
				character_count.insert(make_pair(c, ++temp));
			}

		//Remove space.
		if (character_count.find(' ') != character_count.end())
			character_count.erase(character_count.find(' '));
	}
};
