/*


Freedom Trail


In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.
Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. 
You need to find the minimum number of steps in order to spell all the characters in the keyword.
Initially, the first character of the ring is aligned at 12:00 direction. 
You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.
At the stage of rotating the ring to spell the key character key[i]:
You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. 
The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. 
After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.

Example:

	Input: ring = "godding", key = "gd"
	Output: 4
	Explanation:
	For the first key character 'g', since it is already in place, we just need 1 step to spell this character.
	For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
	Also, we need 1 more step for spelling.
	So the final output is 4.

Note:
	Length of both ring and key will be in range 1 to 100.
	There are only lowercase letters in both strings and might be some duplcate characters in both strings.
	It's guaranteed that string key could always be spelled by rotating the string ring.

@author Zixuan
@date	2018/6/10
*/
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	//To many recursions
	unsigned long long findRotateSteps_1(string ring, string key)
	{
		if (0 == key.length())
			return 0;
		auto ch = key[0];
		unsigned long long min_value = INT_MAX;
		for (unsigned long long i = 0; i < ring.length(); ++i)//string.length() returns unsigned long long?
			if (ring[i] == ch)
			{
				auto min_length = min(i, ring.length() - i);
				auto now_ring = ring.substr(i, ring.length() - i) + ring.substr(0, i);
				min_value = min(min_value, findRotateSteps(now_ring, key.substr(1)) + min_length + 1);
			}

		return min_value;
	}

	//https://leetcode.com/problems/freedom-trail/discuss/98902/Concise-Java-DP-Solution
	/*
	 * I think a we can establish an invariant, or at least an interpretation of what's stored in 'dp':
	 * dp[i][j] is conceptually the minimum steps needed to to complete key[i:], while starting at ring[j]. 
	 * (ignore the steps for spelling, which is added at the end => 'm').
	 * Thus, in the inner-most loop, we looking for all indexes 'k' in ring s.t. ring[k] == key[i]. 
	 * We try to go to all such index 'k' from 'j', calculate the minimum distance to get there => 'step', 
	 * and the total cost will be 'step' + dp[i + 1][k]', 
	 * where the later is the minimum cost of constructing the remaining key[i+1:] starting from 'k'.
	 */
	int findRotateSteps(string ring, string key)
	{
		int n = ring.length();
		int m = key.length();
		vector<vector<int>> dp(m + 1, vector<int>(n));

		for (auto i = m - 1; i >= 0; --i)
			for (auto j = 0; j < n; ++j)
			{
				dp[i][j] = INT_MAX;
				for (auto k = 0; k < n; ++k)
					if (ring[k] == key[i])
					{
						auto diff = abs(j - k);
						auto step = min(diff, n - diff);
						dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
					}
			}

		return dp[0][0] + m;

	}
};

