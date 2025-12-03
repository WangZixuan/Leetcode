/*


Two Best Non-Overlapping Events


You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.


Example 1:
Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Example 2:
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.

Example 3:
Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.


Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106


@author Zixuan
@date	2025/12/3
*/

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(),
            events.end(),
            [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

        vector<int> endTime(events.size(), events[0][1]);
        vector<int> maxValueSoFar(events.size(), events[0][2]);

        for (unsigned i = 1; i < events.size(); ++i)
        {
            endTime[i] = events[i][1];
            maxValueSoFar[i] = max(maxValueSoFar[i - 1], events[i][2]);
        }

        int currentMax = 0;

        for (unsigned i = 0; i < events.size(); ++i)
        {
            auto it = upper_bound(endTime.begin(), endTime.end(), events[i][0] - 1);
            int j = it - endTime.begin() - 1;
            int candidate = 0;
            if (j >= 0)
                candidate = events[i][2] + maxValueSoFar[j];
            else
                candidate = events[i][2];
            currentMax = max(currentMax, candidate);
        }

        return currentMax;
    }
};
