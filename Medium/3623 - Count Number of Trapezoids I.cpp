/*


Count Number of Trapezoids I


You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.


Example 1:
Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]
Output: 3
Explanation:
There are three distinct ways to pick four points that form a horizontal trapezoid:
Using points [1,0], [2,0], [3,2], and [2,2].
Using points [2,0], [3,0], [3,2], and [2,2].
Using points [1,0], [3,0], [3,2], and [2,2].

Example 2:
Input: points = [[0,0],[1,0],[0,1],[2,1]]
Output: 1
Explanation:
There is only one horizontal trapezoid that can be formed.


Constraints:

4 <= points.length <= 105
–108 <= xi, yi <= 108
All points are pairwise distinct.


@author Zixuan
@date	2025/12/2
*/

#include <vector>
#include <map>
using namespace std;

class Solution 
{
public:
    const long long MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points)
    {
        // Group points into each group with same y value
        map<int, long long> countOfEachY;
        for (auto& point : points)
        {
            if (countOfEachY.contains(point[1]))
                countOfEachY[point[1]]++;
            else
                countOfEachY[point[1]] = 1;
        }

        long long sumOfAll = 0;

        for (auto& c : countOfEachY)
        {
            c.second = c.second * (c.second - 1) / 2;
            sumOfAll += c.second;
        }

        long long count = 0;

        for (auto& c : countOfEachY)
        {
            sumOfAll -= c.second;
            count += sumOfAll * c.second;
        }

        return count % MOD;
    }
};
