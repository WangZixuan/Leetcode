/*


Longest Palindromic Subsequence


Example 1:
	Input:
	"bbbab"
	Output:
	4
	One possible longest palindromic subsequence is "bbbb".
Example 2:
	Input:
	"cbbd"
	Output:
	2
	One possible longest palindromic subsequence is "bb".

@author Zixuan
@date	2018/5/29
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestPalindromeSubseq(string s)
	{
		vector<vector<int>> matrix(s.length(), vector<int>(s.length(), 1));

		for (unsigned k = 1; k < s.length(); ++k)//k indicates the length of palindromic subsequence
			for (unsigned i = 0; i < s.length() - k; ++i)
				if (1 == k)
					matrix[i][i + k] = s[i] == s[i + k] ? 2 : 1;
				else
				{
					if (s[i] == s[i + k])
						matrix[i][i + k] = matrix[i + 1][i + k - 1] + 2;
					else
						matrix[i][i + k] = max(matrix[i + 1][i + k - 1], max(matrix[i][i + k - 1], matrix[i + 1][i + k]));
				}

		auto max_value = 0;
		for (auto line : matrix)
			for (auto i : line)
				max_value = max(i, max_value);

		return max_value;
	}
};
