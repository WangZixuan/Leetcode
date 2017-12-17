/*


Shortest Completing Word


Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. 
Such a word is said to complete the given string licensePlate
Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.
It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.
The license plate might have the same letter occurring multiple times. 
For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.

Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.

Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].

@author Zixuan
@date	2017/12/17
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words)
	{
		string licensePlateCopy;
		for (auto c : licensePlate)
			if (c >= 'a'&&c <= 'z')
				licensePlateCopy += c;
			else if (c >= 'A'&&c <= 'Z')
				licensePlateCopy += c - 'A' + 'a';

		sort(licensePlateCopy.begin(), licensePlateCopy.end());

		string currentAnswer = "";

		for (auto c : words)
		{
			if (c.length() < licensePlateCopy.length())
				continue;

			auto copy = c;
			sort(c.begin(), c.end());
			unsigned li = 0, ci = 0;
			while (ci < c.length() && li < licensePlateCopy.length())
			{
				if (c[ci] == licensePlateCopy[li])
				{
					++ci;
					++li;
				}
				else if (c[ci] < licensePlateCopy[li])
					++ci;
				else
					break;
			}
			if (li == licensePlateCopy.length())
			{
				if ("" == currentAnswer)
					currentAnswer = copy;
				else if (currentAnswer.length() > copy.length())
					currentAnswer = copy;
			}

		}
		return currentAnswer;
	}
};
