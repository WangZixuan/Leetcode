/*


Best Time to Buy and Sell Stock IV


You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

Constraints:
1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

@author Zixuan
@date	2025/12/17
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        unsigned dayCount = prices.size();

        // Hint: the dynamic programming states are defined like this. The value dfs(i, j, 0) represents the maximum profit after day i if exactly j transactions have been completed and we end the day holding no stock. 
        // Similarly, dfs(i, j, 1) represents the maximum profit after day i with exactly j completed transactions while holding one stock.
        vector<vector<vector<int>>> dp(dayCount, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int j = 0; j <= k; ++j )
            dp[0][j][1] = -prices[0];

        for (unsigned i = 1; i < dayCount; ++i)
        {
            dp[i][0][1] = dp[i-1][0][1];

            for (unsigned j = 1; j <= k; ++j)
            {
                // After day i, hold no stock
                // Either do nothing when day i-1 holding no stock
                // Or sell stock of day i-1
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);

                // After day i, still hold one stock
                // Either do nothing when day i-1 holding one stock
                // Or buy stock of day i
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }

        int maxValue = 0;
        for (int i = 0; i <= k; ++ i)
            if (maxValue < dp[dayCount-1][i][0])
                maxValue = dp[dayCount-1][i][0];

        return maxValue;
    }
};
