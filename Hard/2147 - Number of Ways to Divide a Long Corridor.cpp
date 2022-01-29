/*


Number of Ways to Divide a Long Corridor


Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.


Example 1:

Input: corridor = "SSPPSPS"
Output: 3
Explanation: There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, each section has exactly two seats.


Example 2:

Input: corridor = "PPSPSP"
Output: 1
Explanation: There is only 1 way to divide the corridor, by not installing any additional dividers.
Installing any would create some section that does not have exactly two seats.


Example 3:

Input: corridor = "S"
Output: 0
Explanation: There is no way to divide the corridor because there will always be a section that does not have exactly two seats.


Constraints:

n == corridor.length
1 <= n <= 10^5
corridor[i] is either 'S' or 'P'.

@author Zixuan
@date	2022/01/29
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
    int numberOfWays(string corridor)
    {
        int length = corridor.length();
        const int modulo = 1e9 + 7;

        // Check first two positions
        int firstTwoPosition = -1;
        bool hasFirstOne = false;
        for (auto i = 0; i < length; ++i)
        {
            if (corridor[i] == 'S' && !hasFirstOne)
            {
                hasFirstOne = true;
            }
            else if (corridor[i] == 'S' && hasFirstOne)
            {
                firstTwoPosition = i;
                break;
            }
        }
        if (firstTwoPosition == -1) return 0;

        // Check last two positions
        int lastTwoPosition = -1;
        bool hasLastOne = false;
        for (auto i = length; i >= 0; --i)
        {
            if (corridor[i] == 'S' && !hasLastOne)
            {
                hasLastOne = true;
            }
            else if (corridor[i] == 'S' && hasLastOne)
            {
                lastTwoPosition = i;
                break;
            }
        }

        // Search plants between first two and last two
        unsigned long long number = 1;
        int currentLast = firstTwoPosition;
        for (auto i = firstTwoPosition + 1; i < lastTwoPosition; ++i)
        {
            if (corridor[i] == 'S')
            {
                // Please pay attention to the potential overflow
                number = number * (i - currentLast) % modulo;
                ++i;

                // Find next S
                while (i <= lastTwoPosition)
                {
                    if (corridor[i] == 'S')
                    {
                        currentLast = i;
                        break;
                    }

                    ++i;
                }

                // Odd number of seats
                if (i >= lastTwoPosition) return 0;
            }
        }

        // If there existing last space
        int left = lastTwoPosition > currentLast ? lastTwoPosition - currentLast : 1;
        return number * left % modulo;
    }
};
