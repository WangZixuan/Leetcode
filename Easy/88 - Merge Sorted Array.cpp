/*


Merge Sorted Array


Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

@author Zixuan
@date	2015/8/13
*/

#include <vector>
using namespace std;
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		if (0 == m + n)
			return;

		//Extra space to reduce time.
        int* space = new int [m + n];

		int i = 0, j = 0;//i is index for nums1, j for nums2.
		int index = 0;//index for space.

		while (i < m && j < n)
		{
			if (nums1[i] < nums2[j])
				space[index++] = nums1[i++];
			else
				space[index++] = nums2[j++];
		}

		//One meets end.
		if (i == m)//nums1 meets end.
			while (j < n)
				space[index++] = nums2[j++];
		else//nums2 meets end.
			while (i < m)
				space[index++] = nums1[i++];

		//Clean nums1 and fill its value.
		nums1.clear();
		nums1.assign(space, space + m + n);

		//DO NOT FORGET THIS!!!
		delete[] space;
		return;
    }
};