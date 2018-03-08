/*


Best Time to Buy and Sell Stock with Cooldown


Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
	prices = [1, 2, 3, 0, 2]
	maxProfit = 3
	transactions = [buy, sell, cooldown, buy, sell]

@author Zixuan
@date	2018/3/8
*/
#include <algorithm>
#include <vector>
using namespace std;

//Reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
class Solution 
{
public:
	//buy[i] = max(sell[i-2]-price, buy[i-1])
	//sell[i] = max(buy[i-1]+price, sell[i-1])
	int maxProfit(vector<int>& prices) 
	{
		int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
		for (auto price : prices) 
		{
			prev_buy = buy;
			buy = max(prev_sell - price, buy);
			prev_sell = sell;
			sell = max(prev_buy + price, sell);
		}
		return sell;
	}
};
