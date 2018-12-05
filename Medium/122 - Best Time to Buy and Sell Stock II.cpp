/*


Best Time to Buy and Sell Stock II


Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

@author Zixuan
@date	2017/01/15
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	int maxProfit(vector<int>& prices) 
	{
		auto total = 0;
		for (auto i = 0; i< static_cast<int>(prices.size())- 1; ++i)
			if (prices[i + 1]>prices[i]) 
				total += prices[i + 1] - prices[i];
		return total;
	}
};
	