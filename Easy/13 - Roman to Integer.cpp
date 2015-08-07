/*


Roman to Integer


Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

@author Zixuan
@date	2015/8/7
*/


#include <map>
#include <string>//http://stackoverflow.com/questions/3709031/mapstring-string-how-to-insert-data-in-this-map
using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		//Init
		map<string, int> basics;

		basics.insert(make_pair("I", 1));
		basics.insert(make_pair("II", 2));
		basics.insert(make_pair("III", 3));
		basics.insert(make_pair("IV", 4));
		basics.insert(make_pair("V", 5));
		basics.insert(make_pair("VI", 6));
		basics.insert(make_pair("VII", 7));
		basics.insert(make_pair("VIII", 8));
		basics.insert(make_pair("IX", 9));

		basics.insert(make_pair("X", 10));
		basics.insert(make_pair("XX", 20));
		basics.insert(make_pair("XX", 30));
		basics.insert(make_pair("XL", 40));
		basics.insert(make_pair("L", 50));
		basics.insert(make_pair("LX", 60));
		basics.insert(make_pair("LXX", 70));
		basics.insert(make_pair("LXXX", 80));
		basics.insert(make_pair("XC", 90));

		basics.insert(make_pair("C", 100));
		basics.insert(make_pair("CC", 200));
		basics.insert(make_pair("CCC", 300));
		basics.insert(make_pair("CD", 400));
		basics.insert(make_pair("D", 500));
		basics.insert(make_pair("DC", 600));
		basics.insert(make_pair("DCC", 700));
		basics.insert(make_pair("DCCC", 800));
		basics.insert(make_pair("CM", 900));

		basics.insert(make_pair("M", 1000));
		basics.insert(make_pair("MM", 2000));
		basics.insert(make_pair("MMM", 3000));

		int retInteger = 0;
		int startPos = 0;
		int length = s.length();

		while (startPos < length)
		{

			if (startPos + 4 <= length)
			{
				int value = searchInMap(basics, s, startPos, 4);
				if (value >= 0)
				{
					retInteger += value;
					startPos += 4;
					continue;
				}
				//else 
				//Search failed.
			}

			if (startPos + 3 <= length)
			{
				int value = searchInMap(basics, s, startPos, 3);
				if (value >= 0)
				{
					retInteger += value;
					startPos += 3;
					continue;
				}
				//else 
				//Search failed.
			}

			if (startPos + 2 <= length)
			{
				int value = searchInMap(basics, s, startPos, 2);
				if (value >= 0)
				{
					retInteger += value;
					startPos += 2;
					continue;
				}
				//else 
				//Search failed.
			}


			int value = searchInMap(basics, s, startPos, 1);
			if (value >= 0)
			{
				retInteger += value;
				startPos += 1;
				continue;
			}
			//else 
			//Won't come here.


		}

		return retInteger;

	}

private:
	int searchInMap(map<string, int> searchMap, string s, int startPos, int digit)
	{
		int retInteger = 0;
		string subStr = s.substr(startPos, digit);

		auto search = searchMap.find(subStr);

		if (search != searchMap.end())
		{
			retInteger += search->second;
			startPos += digit;
			return retInteger;
		}
		else
			return -1;//Search failed.	
	}
};
