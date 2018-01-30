/*


Global and Local Inversions


We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.
The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].
The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].
Return true if and only if the number of global inversions is equal to the number of local inversions.
Example 1:
	Input: A = [1,0,2]
	Output: true
	Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:
	Input: A = [1,2,0]
	Output: false
	Explanation: There are 2 global inversions, and 1 local inversion.
Note:
A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.

@author Zixuan
@date	2018/1/30
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	//Reference: https://discuss.leetcode.com/topic/118712/easy-and-concise-solution-c-java-python
	//Pay attention to this:
	//It also means that we can not find A[i] > A[j] with i+2<=j.
	//In other words, max(A[i]) < A[i + 2]
	bool isIdealPermutation(vector<int>& A)
	{
		int cmax = 0, n = A.size();
		for (auto i = 0; i < n - 2; ++i)
		{
			cmax = max(cmax, A[i]);
			if (cmax > A[i + 2]) 
				return false;
		}
		return true;

	}
};