/*


2 Keys Keyboard


Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
Example 1:
	Input: 3
	Output: 3
	Explanation:
	Intitally, we have one character 'A'.
	In step 1, we use Copy All operation.
	In step 2, we use Paste operation to get 'AA'.
	In step 3, we use Paste operation to get 'AAA'.

Note:
The n will be in the range [1, 1000].

@author Zixuan
@date	2018/6/1
*/

#include <vector>
#include <algorithm>
using namespace std;

#define MAX_STEPS 10001

class Solution
{
public:

	//https://leetcode.com/problems/2-keys-keyboard/solution/
	int minSteps(int n) 
	{
		auto ans = 0, d = 2;
		while (n > 1) 
		{
			while (n % d == 0) 
			{
				ans += d;
				n /= d;
			}
			++d;
		}
		return ans;
	}

	//Memory Limit Exceeded, even use steps[n][n] instead of steps[n+1][n+1]
	int minSteps_(int n)
	{
		if (n <= 1)
			return 0;

		//strps[i][j] indicates: the steps to get i letters with pasting j letters in the last time.
		vector<vector<int>> steps(n + 1, vector<int>(n + 1, MAX_STEPS));
		steps[1][0] = 0;
		steps[2][1] = 2;

		for (auto i = 3; i < n + 1; ++i)
			for (auto j = 1; j < i / 2 + 1; ++j)
			{
				if (0 == i % 2 && j == i / 2)
					steps[i][j] = *min_element(steps[j].begin(), steps[j].end()) + 2;
				else
				{
					if (steps[i - j][j] != MAX_STEPS)
						steps[i][j] = steps[i - j][j] + 1;
				}
			}

		return *min_element(steps.back().begin(), steps.back().end());
	}
};

