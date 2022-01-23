/*


Maximum Running Time of N Computers


You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.


Example 1:

Input: n = 2, batteries = [3,3,3]
Output: 4
Explanation:
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.


Example 2:

Input: n = 2, batteries = [1,1,1,1]
Output: 2
Explanation:
Initially, insert battery 0 into the first computer and battery 2 into the second computer.
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer.
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.


Constraints:

1 <= n <= batteries.length <= 105
1 <= batteries[i] <= 109

@Author Zixuan
@Date 2022-01-23
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // TLE
    long long maxRunTime1(int n, vector<int>& batteries)
    {
        int size = batteries.size();

        if (n > size) return 0;

        // Greedy
        // Move least batteries out and most batteries in
        long long minutes = 0;
        priority_queue<int> batteriesQueue(batteries.begin(), batteries.end());

        while (batteriesQueue.size() >= n)
        {
            vector<int> usedBatteries(n);
            for (int i = 0; i < n; ++i)
            {
                int maxBattery = batteriesQueue.top();
                if (maxBattery <= 0)
                    break;

                usedBatteries[i] = maxBattery;
                batteriesQueue.pop();
            }

            int canUseMinutes = batteriesQueue.empty()? usedBatteries[n - 1] : usedBatteries[n - 1] - batteriesQueue.top() + 1;
            minutes += canUseMinutes;

            // Push back to batteriesQueue
            for (auto v : usedBatteries)
                if (v > canUseMinutes)
                    batteriesQueue.push(v - canUseMinutes);
        }

        return minutes;
    }

    long long maxRunTime(int n, vector<int>& batteries)
    {
        long long sum = 0, minMinutes = batteries[0];

        for (unsigned i = 0; i < batteries.size(); ++i)
        {
            sum += batteries[i];
            minMinutes = minMinutes > batteries[i] ? batteries[i] : minMinutes;
        }

        long long maxMinutes = sum / n, result = minMinutes;

        // Binary search in the feasible space
        // Reference: https://leetcode.com/problems/maximum-running-time-of-n-computers/discuss/1692939/JavaC%2B%2BPython-Sort-Solution-with-Explanation-O(mlogm)
        while (minMinutes <= maxMinutes)
        {
            long long middle = (minMinutes + maxMinutes) / 2;
            if (canRunKMinutes(middle, n, batteries))
            {
                result = middle;
                minMinutes = middle + 1;
            }
            else
            {
                maxMinutes = middle - 1;
            }
        }

        return result;
    }

private:
    bool canRunKMinutes(const long long& k, const int& n, const vector<int>& batteries)
    {
        long long allBatteries = 0;
        for (unsigned i = 0; i < batteries.size(); ++i)
        {
            if (batteries[i] > k)
                allBatteries += k;
            else
                allBatteries += batteries[i];
        }

        return allBatteries >= n * k;
    }
};
