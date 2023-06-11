/*


Minimum Operations to Make a Uni-Value Grid


You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

Example 1:
Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.

Example 2:
Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.

Example 3:
Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10^5
1 <= m * n <= 10^5
1 <= x, grid[i][j] <= 10^4

@author Zixuan
@date	2023/6/11
*/

#include <cmath>
#include <vector>
using namespace std;

class Solution 
{
public:
    int minOperations(vector<vector<int> >& grid, int x) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> nums;
        nums.reserve(m * n);
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                nums.push_back(grid[i][j]);

        sort(nums.begin(), nums.end());
        return stepsToMedian(nums, x, nums[nums.size() / 2]);
    }

private:
    int stepsToMedian(const vector<int>& nums, const int& x, const int& median)
    {
        int steps = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int diff = abs(nums[i] - median);
            if (diff % x == 0)
                steps += diff / x;
            else
                return -1;
        }

        return steps;
    }
};