/*


Employee Free Time


We are given a list avail of employees, which represents the free time for each employee.
Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
Example 1:
Input: avails = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.

Example 2:
Input: avails = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays.
For example, avails[0][0].start = 1, avails[0][0].end = 2, and avails[0][0][0] is not defined.)
Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
Note:
avails and avails[i] are lists with lengths in range [1, 50].
0 <= avails[i].start < avails[i].end <= 10^8.


@author Zixuan
@date   2018/1/7
*/

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

#include <algorithm>

bool compareInterval(const Interval& lhs, const Interval& rhs)
{
	return lhs.start == rhs.start ? lhs.end < rhs.end : lhs.start < rhs.start;
}

#include <vector>
using namespace std;

class Solution
{
public:
	//Reference: User KakaHiguain
	vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails)
	{
		vector<Interval> freeTime;
		vector<Interval> occupiedTime;
		for (auto e : avails)
			for (auto t : e)
				occupiedTime.push_back(t);

		sort(occupiedTime.begin(), occupiedTime.end(), compareInterval);

		auto max = occupiedTime[0].end;
		for (unsigned i = 1; i < occupiedTime.size(); i++)
		{
			auto l = occupiedTime[i].start, r = occupiedTime[i].end;
			if (r <= max)
				continue;
			if (l > max)
			{
				freeTime.push_back(Interval(max, l));
				max = r;
			}
			else 
				max = r;
		}
		return freeTime;

	}
};