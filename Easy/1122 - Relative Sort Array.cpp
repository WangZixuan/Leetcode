/*


Relative Sort Array


Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
	Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
	Output: [2,2,2,1,4,3,3,9,6,7,19]

Constraints:
	arr1.length, arr2.length <= 1000
	0 <= arr1[i], arr2[i] <= 1000
	Each arr2[i] is distinct.
	Each arr2[i] is in arr1.

@author Zixuan
@date	2019/7/25
*/

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
	{
		vector<int> countInArr1(1001, 0);
		for (auto i : arr1)
			++countInArr1[i];

		vector<int> result(arr1.size());

		unsigned index = 0;
		for (auto i : arr2)
		{
			auto count = countInArr1[i];
			while (count-- > 0) //Wow, dangerous!
				result[index++] = i;
			countInArr1[i] = 0;
		}

		for (unsigned i = 0; i < countInArr1.size(); ++i)
			if (countInArr1[i] != 0) // What if the number of those who are not in arr2 is more than 1?
				while (countInArr1[i]-- > 0) //Wow, dangerous again!
					result[index++] = i;

		return result;
	}
};

