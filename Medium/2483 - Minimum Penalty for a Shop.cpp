/*


Minimum Penalty for a Shop


You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':
if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:
For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.
Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

Example 1:
Input: customers = "YYNY"
Output: 2
Explanation:
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.

Example 2:
Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.

Example 3:
Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.

Constraints:
1 <= customers.length <= 10^5
customers consists only of characters 'Y' and 'N'.

@author Zixuan
@date	2025/12/26
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        size_t len = customers.length();
        vector<int> YFromEndToBeginning(len, 0);
        vector<int> NFromBeginingToEnd(len, 0);

        if (customers[len - 1] == 'Y')
            YFromEndToBeginning[len - 1] = 1;

        if (customers[0] == 'N')
            NFromBeginingToEnd[0] = 1;

        // From end to beginning, compute YFromEndToBeginning
        for (int i = len - 2; i >= 0; --i)
        {
            YFromEndToBeginning[i] = customers[i] == 'Y' ? YFromEndToBeginning[i + 1] + 1 : YFromEndToBeginning[i + 1];
        }

        int penalty = YFromEndToBeginning[0];
        int closingHour = 0;

        bool specialCase = false;

        for (size_t i = 1; i < len; ++i)
        {
            NFromBeginingToEnd[i] = customers[i] == 'N' ? NFromBeginingToEnd[i - 1] + 1 : NFromBeginingToEnd[i - 1];

            int currentPenalty = NFromBeginingToEnd[i - 1] + YFromEndToBeginning[i];

            if (currentPenalty < penalty)
            {
                closingHour = i;
                penalty = currentPenalty;
            }
            else if (currentPenalty == penalty && i == len - 1)
            {
                specialCase = true;
            }
        }

        if (customers[len - 1] == 'Y' && (closingHour == len - 1 || specialCase))
            return len;

        return closingHour;
    }
};
