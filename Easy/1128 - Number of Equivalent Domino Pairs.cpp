/*


Number of Equivalent Domino Pairs


Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.
Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Example 1:
	Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
	Output: 1

Constraints:
	1 <= dominoes.length <= 40000
	1 <= dominoes[i][j] <= 9

@author Zixuan
@date	2019/7/25
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes)
	{
		vector<vector<int>> pairCount(10, vector<int>(10, 0));

		for (auto d : dominoes)
			++pairCount[d[0]][d[1]];

		auto count = 0;

		for (auto i = 1; i < 10; ++i)
			for (auto j = 1; j < 10; ++j)
				count += pairCount[i][j] * (pairCount[i][j] - 1) / 2;

		for (auto i = 1; i < 10; ++i)
			for (auto j = i + 1; j < 10; ++j)
				count += pairCount[i][j] * pairCount[j][i];

		return count;
	}
};
