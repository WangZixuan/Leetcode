/*


Hamming Distance


The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ¡Ü x, y < 231.
Example:
	Input: x = 1, y = 4

	Output: 2

	Explanation:
	1   (0 0 0 1)
	4   (0 1 0 0)
		   ¡ü   ¡ü

	The above arrows point to positions where the corresponding bits are different.

@author Zixuan
@date	2016/12/24
*/

class Solution 
{
public:
	int hammingDistance(int x, int y)
	{
		auto count = 0;
		while (0 != x || 0 != y)
		{
			auto halfX = x >> 1;
			auto halfY = y >> 1;
			if (x - 2 * halfX != y - 2 * halfY)
				++count;

			x = halfX;
			y = halfY;
		}
		return count;
	}
};