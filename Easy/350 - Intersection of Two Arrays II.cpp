/*


Intersection of Two Arrays II


Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.


Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

@author Zixuan
@date	2016/6/28
*/

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
	{
		map<int, int> map1;
		countItemsTimes(nums1, map1);

		map<int, int>map2;
		countItemsTimes(nums2, map2);

		vector<int> result;

		for (auto it1 = map1.begin(); it1 != map1.end(); ++it1)
		{
			auto it2 = map2.find(it1->first);
			if (it2 != map2.end())//Found.
			{
				auto count = min(it1->second, it2->second);
				while (count > 0)
				{
					result.push_back(it1->first);
					--count;
				}
			}

		}

		return result;
	}
private:
	void countItemsTimes(vector<int>& nums, map<int, int>& count)
	{
		vector<int> items, times;

		for (auto i : nums)
		{
			auto it = find(items.begin(), items.end(), i);
			if (it == items.end())//Not found.
			{
				items.push_back(i);
				times.push_back(1);
			}
			else//Found.
			{
				auto index = distance(items.begin(), it);
				++times[index];
			}
		}

		//Make those two vectors a map.
		for (auto i = 0; i < items.size(); ++i)
			count.insert(make_pair(items[i], times[i]));
	}
};
