/*


Compare Version Numbers


Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

@author Zixuan
@date	2015/8/25
*/
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		vector<int> num1, num2;

		//Split string
		string temp;
		for (unsigned int i = 0; i < version1.length(); ++i)
			if ('.' == version1[i])
			{
				num1.push_back(atoi(temp.c_str()));
				temp.clear();
			}
			else
				temp += version1[i];

		num1.push_back(atoi(temp.c_str()));
			
		temp.clear();
		for (unsigned int i = 0; i < version2.length(); ++i)
			if ('.' == version2[i])
			{
				num2.push_back(atoi(temp.c_str()));
				temp.clear();
			}
			else
				temp += version2[i];

		num2.push_back(atoi(temp.c_str()));

		int minLength = (num1.size() < num2.size()) ? num1.size() : num2.size();
		int minIndex = (num1.size() < num2.size()) ? 1 : 2;
		for (int i = 0; i < minLength; ++i)
		{
			if (num1[i] > num2[i])
				return 1;
			else if (num1[i] < num2[i])
				return -1;
		}
		
		bool allZero = true;
		switch (minIndex)
		{
		case 1://num2 is longer
			for (int i = minLength; i < num2.size(); ++i)
				if (num2[i] != 0)
				{
					allZero = false;
					break;
				}
			break;
		case 2://num1 is longer
			for (int i = minLength; i < num1.size(); ++i)
				if (num1[i] != 0)
				{
					allZero = false;
					break;
				}
			break;
		}

		if (allZero)
			return 0;

		if (num1.size() == num2.size())
			return 0;
		else if (num1.size() > num2.size())
			return 1;
		else
			return -1;
	}
};
