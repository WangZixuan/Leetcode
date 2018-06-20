/*


Coin Change


You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
Example 1:
	Input: coins = [1, 2, 5], amount = 11
	Output: 3
	Explanation: 11 = 5 + 5 + 1
Example 2:
	Input: coins = [2], amount = 3
	Output: -1
Note:
	You may assume that you have an infinite number of each kind of coin.

@author Zixuan
@date	2018/6/20
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	//https://leetcode.com/problems/coin-change/solution/
	int coinChange(vector<int>& coins, int amount) 
	{
		vector<int> minCountSoFar(amount, 0);
		return coinChangeWithStorage(coins, amount, minCountSoFar);
	}

private:
	int coinChangeWithStorage(const vector<int>& coins, int amount, vector<int>& minCountSoFar)
	{
		if (0 == amount)
			return 0;
		if (amount < 0)
			return -1;

		if (minCountSoFar[amount - 1] != 0)
			return minCountSoFar[amount - 1];

		auto min = INT_MAX;
		for (auto coin : coins)
		{
			auto res = coinChangeWithStorage(coins, amount - coin, minCountSoFar);
			if (res >= 0 && res < min)
				min = 1 + res;
		}
		minCountSoFar[amount - 1] = min == INT_MAX ? -1 : min;
		return minCountSoFar[amount - 1];
	}
};
