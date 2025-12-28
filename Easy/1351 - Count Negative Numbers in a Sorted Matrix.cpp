/*


Count Negative Numbers in a Sorted Matrix


Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

Follow up: Could you find an O(n + m) solution?

@author Zixuan
@date	2025/12/28
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        const int columnSize = grid[0].size();
        auto lastRowPosition = columnSize;
        for (auto &row : grid)
        {
            auto it = upper_bound(row.begin(), row.begin() + lastRowPosition, 0, std::greater<int>());
            lastRowPosition = it - row.begin();
            count += columnSize - lastRowPosition;
        }

        return count;
    }
};
