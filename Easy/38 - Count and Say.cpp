/*


Count and Say


The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

@author Zixuan
@date	2015/8/12
*/

#include <string>
using namespace std;

class Solution 
{
public:
    string countAndSay(int n) 
	{
		string sequence("1");
		for (int i = 1; i < n; ++i)
		{
			string temp = sequence;
			sequence.clear();

			//It is sure temp.length() >= 1.
			//Initalization.
			char thisDigit = temp[0];
			int thisTime = 0;

			for (char j : temp)
			{
				if (j == thisDigit)
					++thisTime;
				else
				{
					sequence += (thisTime + '0');
					sequence += thisDigit;

					//Reconfigure thisDigit and thisTime;
					thisDigit = j;
					thisTime = 1;
				}
			}

			//There must be an end.
			sequence += (thisTime + '0');
			sequence += thisDigit;
		}

		return sequence;
    }
};
