/*


Arithmetic Slices


A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, these are arithmetic sequence:
	1, 3, 5, 7, 9
	7, 7, 7, 7
	3, -1, -5, -9
The following sequence is not arithmetic.
	1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
The function should return the number of arithmetic slices in the array A.

Example:
	A = [1, 2, 3, 4]

	return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

@author Zixuan
@date	2018/3/29
*/
#include <vector>
using namespace std;

class Solution 
{
public:
	int numberOfArithmeticSlices(vector<int>& A)
	{
		if (A.size() <= 2)
			return 0;

		vector<int> indexes(A.size(), -1);
		auto currentDifference = A[1] - A[0];

		for (unsigned i = 2; i < A.size(); ++i)
		{
			if (currentDifference == A[i] - A[i - 1])
				indexes[i] = indexes[i - 1] == -1 ? i - 2 : indexes[i - 1];
			else
				currentDifference = A[i] - A[i - 1];
		}

		auto count = 0;
		auto current = -1;
		for (unsigned i = 2; i < indexes.size(); ++i)
		{
			if (indexes[i] != -1)
			{
				current = current == -1 ? i : current;
				count += i - current + 1;
			}
			else
				current = -1;
		}

		return count;
	}
};
