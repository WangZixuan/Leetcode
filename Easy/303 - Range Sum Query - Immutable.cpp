/*


Range Sum Query - Immutable


Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3



Note:

1.You may assume that the array does not change.
2.There are many calls to sumRange function.

@author Zixuan
@date	2016/5/28
*/

#include <vector>
using namespace std;
class NumArray 
{
public:
	NumArray(vector<int> &nums) 
	{
		auto temp = 0;
		for (auto n : nums)
		{
			temp += n;
			sumTillThis.push_back(temp);
		}
	}

	int sumRange(int i, int j) 
	{
		if (0 == i)
			return sumTillThis[j];
		return sumTillThis[j] - sumTillThis[i - 1];
	}
private:
	vector<int> sumTillThis;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);