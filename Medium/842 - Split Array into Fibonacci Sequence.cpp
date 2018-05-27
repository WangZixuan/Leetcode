/*


Split Array into Fibonacci Sequence


Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:
	Input: "123456579"
	Output: [123,456,579]
Example 2:
	Input: "11235813"
	Output: [1,1,2,3,5,8,13]
Example 3:
	Input: "112358130"
	Output: []
	Explanation: The task is impossible.
Example 4:
	Input: "0123"
	Output: []
	Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
Example 5:
	Input: "1101111"
	Output: [110, 1, 111]
	Explanation: The output [11, 0, 11, 11] would also be accepted.

@author Zixuan
@date	2018/5/27
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> splitIntoFibonacci(string S)
	{
		vector<int> splits;
		if (S.length() < 3)
			return splits;

		for (auto i = 1; i < min(11, static_cast<int>(S.length()) / 2 + 1); ++i)//i indicates the length of the first number
		{
			if (i == 10 && S.substr(0, i) > "2147483647")//ATTENTION HERE! Check range before stoi()!
				break;

			const auto first_c = stoi(S.substr(0, i));

			if (digitsCount(first_c) != i)
				continue;

			for (auto j = 1; j < min(11, static_cast<int>(S.length())); ++j)//j indicates the length of the second number
			{
				if (j == 10 && S.substr(i, j) > "2147483647")
					break;

				const auto second_c = stoi(S.substr(i, j));

				if (digitsCount(second_c) != j)
					continue;

				if (i + j == S.length())
					continue;

				auto pivot = i + j;
				//Now we check the substring of the back.
				auto flag = true;
				splits.clear();
				splits.push_back(first_c);
				splits.push_back(second_c);

				auto first = first_c;
				auto second = second_c;

				while (true)
				{
					if (pivot == S.length())
						break;
					auto now = first + second;

					//Overflow
					if (now < 0)
					{
						flag = false;
						break;
					}

					auto digitsC = digitsCount(now);

					if (pivot + digitsC > S.length())
					{
						flag = false;
						break;
					}

					auto predict = S.substr(pivot, digitsC);

					if (predict.length() >= 11 || predict.length() == 10 && predict > "2147483647")
					{
						flag = false;
						break;
					}

					if (now == stoi(predict))
					{
						splits.push_back(now);
						first = second;
						second = now;
						pivot += digitsC;
					}
					else
					{
						flag = false;
						break;
					}
				}

				if (flag)
					return splits;
			}
		}

		splits.clear();
		return splits;

	}

private:
	int digitsCount(int x)
	{
		if (0 == x)
			return 1;
		auto count = 0;
		while (x > 0)
		{
			++count;
			x /= 10;
		}
		return count;
	}
};
