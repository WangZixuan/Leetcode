/*


Partition Labels 


A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts. 

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:
S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

@author Zixuan
@date	2018/1/14
*/
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
	vector<int> partitionLabels(string S)
	{
		vector<int> lastPosition(26, -1);
		vector<int> countPatition;
		vector<string> strPatition;

		for (auto c : S)
		{
			if (lastPosition[c - 'a'] == -1)//New a patition
			{
				lastPosition[c - 'a'] = countPatition.size();
				countPatition.push_back(1);
				strPatition.push_back(string(1, c));
			}
			else
			{
				auto position = lastPosition[c - 'a'];
				//Merge these patitions
				string all;
				for (int p = countPatition.size() - 1; p > position; --p)
				{
					//Pop
					countPatition.pop_back();

					all = strPatition[p] + all;
					strPatition.pop_back();
				}

				all = strPatition[position] + all + string(1, c);
				strPatition[position] = all;
				countPatition[position] = all.length();

				//Modify flags of lastPosition
				for (auto i : all)
					lastPosition[i - 'a'] = position;

			}
		}

		return countPatition;
	}
};