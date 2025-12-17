/*


Best Time to Buy and Sell Stock V


You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.
You are allowed to make at most k transactions, where each transaction can be either of the following:
Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].
Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.
Return the maximum total profit you can earn by making at most k transactions.

Example 1:
Input: prices = [1,7,9,8,2], k = 2
Output: 14
Explanation:
We can make $14 of profit through 2 transactions:
A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.

Example 2:
Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
Output: 36
Explanation:
We can make $36 of profit through 3 transactions:
A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.

Constraints:
2 <= prices.length <= 10^3
1 <= prices[i] <= 10^9
1 <= k <= prices.length / 2

@author Zixuan
@date	2025/12/17
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    long long maximumProfit(vector<int>& prices, int k)
    {
        unsigned dayCount = prices.size();

        // The value dp(i, j, 0) represents the maximum profit after day i if exactly j transactions have been completed and we end the day holding no stock. 
        // dp(i, j, 1) represents the maximum profit after day i with exactly j completed transactions while holding one stock.
        // dp(i, j, 2) represents the maximum profit after day i with exactly j completed transactions while holding minus one stock.
        vector<vector<vector<long long>>> dp(dayCount, vector<vector<long long>>(k + 1, vector<long long>(3, 0)));
        for (int j = 0; j <= k; ++j )
        {
            dp[0][j][1] = -prices[0];
            dp[0][j][2] = prices[0];
        }

        for (unsigned i = 1; i < dayCount; ++i)
        {
            dp[i][0][1] = dp[i-1][0][1];
            dp[i][0][2] = dp[i-1][0][2];

            for (unsigned j = 1; j <= k; ++j)
            {
                // After day i, hold no stock
                // Either do nothing when day i-1 holding no stock
                // Or sell stock of day i when day i-1 holding one
                // Or buy stock of day i when day i-1 holding minus one
                dp[i][j][0] = max(dp[i-1][j][0], max(dp[i-1][j][1] + prices[i], dp[i-1][j][2] - prices[i]));

                // After day i, still hold one stock
                // Either do nothing when day i-1 holding one stock
                // Or buy stock of day i when day i-1 holding zero
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);

                // After day i, hold minus one stock
                // Either do nothing when day i-1 holding minus one stock
                // Or sell stock of day i when day i-1 holding zero
                dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][0] + prices[i]);
            }
        }

        long long maxValue = 0;
        for (int i = 0; i <= k; ++ i)
            if (maxValue < dp[dayCount-1][i][0])
                maxValue = dp[dayCount-1][i][0];

        return maxValue;
    }
};
