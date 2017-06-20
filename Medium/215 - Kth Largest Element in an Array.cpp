/*


Kth Largest Element in an Array


Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

@author Zixuan
@date 2017/6/20
*/

#include <vector>
using namespace std;

class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		return findKthInOrder(nums, nums.size() - k, 0, nums.size() - 1);
	}

private:
	int findKthInOrder(vector<int>& nums, int k, int start, int end)
	{
		auto mid = partition(nums, start, end);
		if (mid == k)
			return nums[start + mid];
		if (mid > k)
			return findKthInOrder(nums, k, start, start + mid - 1);
		return findKthInOrder(nums, k - mid - 1, start + mid + 1, end);
	}

	//Do this like quick sort.
	int partition(vector<int>& nums, int start, int end)
	{
		auto pivot = nums[end];
		auto pivotPos = end;
		auto i = start, j = end - 1;
		while (i<j)
		{
			if (nums[i]>pivot)
			{
				nums[pivotPos] = nums[i];
				nums[i] = nums[j];
				nums[j] = pivot;
				--pivotPos;
				--j;
			}
			else
				++i;
		}

		//Now i==j
		if (nums[i] > pivot)
		{
			nums[pivotPos] = nums[i];
			nums[i] = pivot;
			--pivotPos;
		}
		return pivotPos - start;//Local coordinate.
	}
};
