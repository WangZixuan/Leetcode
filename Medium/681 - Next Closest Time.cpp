/*


Next Closest Time


Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
Example 1:
	Input: "19:34"
	Output: "19:39"
	Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  
	It is not 19:33, because this occurs 23 hours and 59 minutes later.

Example 2:
	Input: "23:59"
	Output: "22:22"
	Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. 
	It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

@author Zixuan
@date	2017/10/15
*/

#include <set>
#include <string>
using namespace std;
class Solution 
{
public:
	string nextClosestTime(string time)
	{
		set<int> digits;
		auto position = -1;

		for (auto i = 0; i < time.length(); ++i)
			if (time[i] != ':')
				digits.insert(time[i] - '0');
			else
				position = i;

		auto hour = stoi(time.substr(0, position));
		auto minute = stoi(time.substr(position + 1));

		while (true)
		{
			if (++minute == 60)
			{
				if (++hour == 24)
					hour = 0;
				minute = 0;
			}

			//Check
			string hour_str;
			string minute_str;
			if (check(hour, digits, hour_str) && check(minute, digits, minute_str))
				return hour_str + ":" + minute_str;

		}

	}

private:
	bool check(int time, set<int>& digits, string& time_str)
	{
		if (time < 10 && digits.find(time) != digits.end() && digits.find(0) != digits.end())
		{
			time_str = digits.find(0) != digits.end() ? "0" : "";
			time_str += to_string(time);
			return true;
		}
		auto ten = time / 10;
		auto one = time % 10;
		if (digits.find(ten) != digits.end() && digits.find(one) != digits.end())
		{
			time_str = to_string(time);
			return true;
		}
		return false;
	}
};
