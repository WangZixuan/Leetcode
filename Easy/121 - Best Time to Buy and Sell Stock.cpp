/*


Best Time to Buy and Sell Stock


Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Example 1:
	Input: [7, 1, 5, 3, 6, 4]
	Output: 5

	max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:
	Input: [7, 6, 4, 3, 1]
	Output: 0

	In this case, no transaction is done, i.e. max profit = 0.

@author Zixuan
@date	2018/3/7
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
	int maxProfit(vector<int>& prices) 
	{
		if (prices.size() <= 1)
			return 0;

		auto value = 0;
		auto minSoFar = prices[0];

		unsigned i = 1;
		while (i < prices.size())
		{
			if (prices[i] < prices[i - 1])
			{
				value = max(value, prices[i - 1] - minSoFar);
				minSoFar = min(minSoFar, prices[i]);
			}
			++i;
		}

		return max(value, prices.back() - minSoFar);//Deal with mono increase sequence.
	}
};