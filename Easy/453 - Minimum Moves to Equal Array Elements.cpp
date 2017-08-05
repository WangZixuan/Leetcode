/*


Minimum Moves to Equal Array Elements


Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
Example:
	Input:
	[1,2,3]

	Output:
	3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

@author Zixuan
@date	2017/8/5
*/
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution 
{
public:
	//Reference: https://discuss.leetcode.com/topic/66737/it-is-a-math-question
	int minMoves(vector<int>& nums)
	{
		auto it = min_element(nums.begin(), nums.end());
		auto sum = accumulate(nums.begin(), nums.end(), 0);
		return sum - *it*nums.size();
	}
};