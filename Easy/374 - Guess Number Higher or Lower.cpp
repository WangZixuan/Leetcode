/*


Guess Number Higher or Lower


We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.
You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
	-1 : My number is lower
	1 : My number is higher
	0 : Congrats! You got it!
Example:
	n = 10, I pick 6.

	Return 6.

@author Zixuan
@date	2017/01/15
*/

#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
//int guess(int num)
//{
//	cout << "my guess is " << num<<endl;
//	int c;
//	cin >> c;
//	return c;
//}

class Solution 
{
public:
	int guessNumber(int n) 
	{
		return guessNumberInRange(1, n);
	}
private:
	int guessNumberInRange(int begin, int end)
	{
		auto myGuess = guess(begin + (end - begin) / 2);//(end + begin) / 2 is not acceptable because it may exceed INT_MAX.
		switch (myGuess)
		{
		case -1:
			return guessNumberInRange(begin, begin + (end - begin) / 2 - 1);
		case 1:
			return guessNumberInRange(begin + (end - begin) / 2 + 1, end);
		case 0:
			return begin + (end - begin) / 2;
		}
	}
};
