/*


Generate Parentheses


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
	[
		"((()))",
		"(()())",
		"(())()",
		"()(())",
		"()()()"
	]

@author Zixuan
@date	2016/9/4
*/

#include <vector>
#include <set>
using namespace std;
class Solution 
{
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> result;
		if (0 >= n)
			return result;
		result.push_back("()");
		if (1 == n)
			return result;
		for (auto i = 1; i < n; ++i)
		{
			set<string> temp;
			for (auto str : result)
			{
				temp.insert("()" + str);

				//Search each "("
				for (auto j = 0; j < str.length(); ++j)
					if (str[j] == '(')
						temp.insert(str.substr(0, j + 1) + "()" + str.substr(j + 1));
			}
			result.resize(temp.size());
			copy(temp.begin(), temp.end(), result.begin());
		}
		return result;
	}
};
