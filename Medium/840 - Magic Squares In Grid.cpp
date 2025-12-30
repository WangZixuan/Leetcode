/*

Magic Squares In Grid


A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

Example 1:
Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation:
In total, there is only one magic square inside the given grid.

Example 2:
Input: grid = [[8]]
Output: 0

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15

@author Zixuan
@date	2025/12/28
*/

#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        if (grid.size() <= 2 || grid[0].size() <= 2)
            return 0;

        // Only eight acceptable matrixes
        vector<vector<int>> acc = {
            {4, 3, 8, 9, 5, 1, 2, 7, 6},
            {8, 3, 4, 1, 5, 9, 6, 7, 2},
            {8, 1, 6, 3, 5, 7, 4, 9, 2},
            {4, 9, 2, 3, 5, 7, 8, 1, 6},
            {2, 7, 6, 9, 5, 1, 4, 3, 8},
            {6, 7, 2, 1, 5, 9, 8, 3, 4},
            {6, 1, 8, 7, 5, 3, 2, 9, 4},
            {2, 9, 4, 7, 5, 3, 6, 1, 8}};

        int count = 0;
        for (size_t i = 0; i < grid.size() - 2; ++i)
            for (size_t j = 0; j < grid[0].size() - 2; ++j)
            {
                // Compare with acc
                for (auto &v : acc)
                {
                    if (grid[i][j] == v[0] &&
                        grid[i][j + 1] == v[1] &&
                        grid[i][j + 2] == v[2] &&
                        grid[i + 1][j] == v[3] &&
                        grid[i + 1][j + 1] == v[4] &&
                        grid[i + 1][j + 2] == v[5] &&
                        grid[i + 2][j] == v[6] &&
                        grid[i + 2][j + 1] == v[7] &&
                        grid[i + 2][j + 2] == v[8])
                        ++count;
                }
            }

        return count;
    }
};
