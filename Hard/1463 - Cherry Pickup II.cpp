/*
Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.


Example 1:
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

Example 2:
Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.

Example 3:
Input: grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
Output: 22

Example 4:
Input: grid = [[1,1],[1,1]]
Output: 4

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100

@author Zixuan
@date 2021/2/15
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int rowCount = grid.size();
        int colCount = grid[0].size();

        // If robot 1 starts at grid[row][i] and robot 2 starts at grid[row][j], dp[row][i][j] is the max cherries they can get.
        vector<vector<vector<int>>> dp(rowCount, vector<vector<int>>(colCount, vector<int>(colCount, 0)));

        // Initialize last row
        for (auto i = 0; i < colCount; ++i)
        {
            for (auto j = 0; j < colCount; ++j)
            {
                if (i == j)
                    dp[rowCount - 1][i][j] = grid[rowCount - 1][i];
                else
                    dp[rowCount - 1][i][j] = grid[rowCount - 1][i] + grid[rowCount - 1][j];
            }
        }

        for (auto row = rowCount - 2; row >= 0; --row)
        {
            for (auto i = 0; i < colCount; ++i)
            {
                for (auto j = 0; j < colCount; ++j)
                {
                    int valueThisRow = i == j ? grid[row][i] : grid[row][i] + grid[row][j];

                    int maxCherries = 0;

                    // Nine directions
                    if (i >= 1 && j >= 1)
                        maxCherries = max(maxCherries, dp[row + 1][i - 1][j - 1] + valueThisRow);
                    if (i >= 1)
                        maxCherries = max(maxCherries, dp[row + 1][i - 1][j] + valueThisRow);
                    if (i >= 1 && j < colCount - 1)
                        maxCherries = max(maxCherries, dp[row + 1][i - 1][j + 1] + valueThisRow);

                    if (j >= 1)
                        maxCherries = max(maxCherries, dp[row + 1][i][j - 1] + valueThisRow);
                        maxCherries = max(maxCherries, dp[row + 1][i][j] + valueThisRow);
                    if (j < colCount - 1)
                        maxCherries = max(maxCherries, dp[row + 1][i][j + 1] + valueThisRow);

                    if (i < colCount - 1 && j >= 1)
                        maxCherries = max(maxCherries, dp[row + 1][i + 1][j - 1] + valueThisRow);
                    if (i < colCount - 1)
                        maxCherries = max(maxCherries, dp[row + 1][i + 1][j] + valueThisRow);
                    if (i < colCount - 1 && j < colCount - 1)
                        maxCherries = max(maxCherries, dp[row + 1][i + 1][j + 1] + valueThisRow);

                    dp[row][i][j] = maxCherries;
                }
            }
        }

        return dp[0][0][colCount - 1];
    }
};
