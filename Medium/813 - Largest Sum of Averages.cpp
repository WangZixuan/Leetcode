/*


Largest Sum of Averages


We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?
Note that our partition must use every number in A, and that scores are not necessarily integers.
Example:
	Input:
	A = [9,1,2,3,9]
	K = 3
	Output: 20
	Explanation:
	The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
	We could have also partitioned A into [9, 1], [2], [3, 9], for example.
	That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

Note:
	1 <= A.length <= 100.
	1 <= A[i] <= 10000.
	1 <= K <= A.length.
	Answers within 10^-6 of the correct answer will be accepted as correct.

@author Zixuan
@date 2018/5/30
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	double largestSumOfAverages(vector<int>& A, int K) 
	{
		//https://leetcode.com/problems/largest-sum-of-averages/solution/
		int len = A.size();
		vector<int> P(1, 0);
		for (int i = 0; i < len; i++)
			P.push_back(P.back() + A[i]);

		vector<double> dp;
		for (int i = 0; i < len; i++)
			dp.push_back(average(P, i, len));

		//Similar to problem 516. Length first.
		for (int m = 0; m < K - 1; m++)
			for (int i = 0; i < len; i++)
				for (int j = i + 1; j < len; j++)
					dp[i] = max(dp[i], average(P, i, j) + dp[j]);
		return dp[0];
	}

	double average(const vector<int> &P, int i, int j) 
	{
		return double(P[j] - P[i]) / (j - i);
	}

};
