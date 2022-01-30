/*


Number of Smooth Descent Periods of a Stock


You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.


Example 1:

Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.


Example 2:

Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.


Example 3:

Input: prices = [1]
Output: 1
Explanation: There is 1 smooth descent period: [1]


Constraints:

1 <= prices.length <= 10^5
1 <= prices[i] <= 10^5

@author Zixuan
@date	2022/01/30
*/


#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
using namespace std;

class Solution 
{
public:
    long long getDescentPeriods(vector<int>& prices) 
    {

        long long count = 1;
        long long last = 1;
        for (unsigned i = 1; i < prices.size(); ++i)
        {
            if (prices[i - 1] - 1 != prices[i])
                last = 0;

            count += ++last;
        }

        return count;
    }
};
