/*


Best Time to Buy and Sell Stock with Transaction Fee


Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.
You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. 
You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
Return the maximum profit you can make.
Example 1:
	Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
	Output: 8
	Explanation: The maximum profit can be achieved by:
	Buying at prices[0] = 1
	Selling at prices[3] = 8
	Buying at prices[4] = 4
	Selling at prices[5] = 9
	The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Note:
	0 < prices.length <= 50000.
	0 < prices[i] < 50000.
	0 <= fee < 50000.

@author Zixuan
@date	2017/10/22
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int maxProfit(vector<int>& prices, int fee) 
	{
		//Reference: https://discuss.leetcode.com/topic/107977/c-concise-solution-o-n-time-o-1-space
		//s0 = profit having no stock
		//s1 = profit having 1 stock
		//update s0 by selling the stock from s1, so s0 = max(s0, s1+p-fee);
		//update s1 by buying the stock from s0, so s1 = max(s1, s0-p);
		auto s0 = 0, s1 = -1000000;
		for (auto p : prices) 
		{
			auto temp = s0;
			s0 = max(s0, s1 + p - fee);
			s1 = max(s1, temp - p);
		}
		return s0;

	}
};
