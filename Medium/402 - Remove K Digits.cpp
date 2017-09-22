/*


Remove K Digits


Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1:
	Input: num = "1432219", k = 3
	Output: "1219"
	Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
	Input: num = "10200", k = 1
	Output: "200"
	Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
	Input: num = "10", k = 2
	Output: "0"
	Explanation: Remove all the digits from the number and it is left with nothing which is 0.

@author Zixuan
@date	2017/9/22
*/

#include <string>
#include <iostream>
using namespace std;

class Solution 
{
public:
	//Reference: https://discuss.leetcode.com/topic/59871/two-algorithms-with-detailed-explaination
	string removeKdigits(string num, int k) 
	{
		string result = "";
		for (auto i = 0; i < num.length(); ++i)
		{
			if (0 == k)
			{
				result += num.substr(i);
				break;
			}

			if (0 == result.length() || result.back() <= num[i])
				result.push_back(num[i]);
			else
			{	//compare result.back() and num[i]
				while (!result.empty() && k > 0 && result.back() > num[i])
				{
					result.pop_back();
					--k;
				}
				result.push_back(num[i]);
			}
		}

		if (k > 0)
			result = result.substr(0, result.length() - k);

		auto index = 0;
		for (auto i = 0; i < result.length(); ++i)
			if (result[i] == '0')
				++index;
			else
				break;
		result = result.substr(index);


		return result.length() > 0 ? result : "0";
	}
};

