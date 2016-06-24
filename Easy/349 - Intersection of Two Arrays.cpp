/*


Intersection of Two Arrays


Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

Each element in the result must be unique.
The result can be in any order.


@author Zixuan
@date	2016/6/24
*/

#include <vector>
#include <algorithm>
#include <iterator>

class Solution
{
public:
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		std::vector<int> v_intersection;

		set_intersection(nums1.begin(), nums1.end(),
			nums2.begin(), nums2.end(),
			back_inserter(v_intersection));

		v_intersection.erase(std::unique(v_intersection.begin(), v_intersection.end()), v_intersection.end());//Remove duplicates.

		return v_intersection;
	}
};
