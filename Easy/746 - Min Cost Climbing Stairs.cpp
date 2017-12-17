/*


Min Cost Climbing Stairs


On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

@author Zixuan
@date	2017/12/17
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int minCostClimbingStairs(vector<int>& cost)
	{
		if (cost.size() <= 2)
			return cost.back();

		vector<int> stepsMin2Values{ cost[0], cost[1] };

		for (unsigned i = 2; i < cost.size(); ++i)
			stepsMin2Values[i % 2] = min(stepsMin2Values[i % 2] + cost[i], stepsMin2Values[(i + 1) % 2] + cost[i]);
		return min(stepsMin2Values[0], stepsMin2Values[1]);
	}
};

int main()
{
	vector<int> v{ 0,1,1,0 };
	Solution s;
	s.minCostClimbingStairs(v);
	return 0;
}