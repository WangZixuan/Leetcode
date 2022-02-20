/*


Remove Covered Intervals


Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.


Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.


Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1


Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li <= ri <= 10^5
All the given intervals are unique.

@Author Zixuan
@Date 2022-02-20
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
    // Or try greedy?
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        // Sort based on intervals
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& left, const vector<int>& right)
            {
                return (left[1] - left[0]) < (right[1] - right[0]);
            });

        const int size = intervals.size();
        int result = size;

        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                if (intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1])
                {
                    --result;
                    break;
                }
            }
        }

        return result;
    }
};
