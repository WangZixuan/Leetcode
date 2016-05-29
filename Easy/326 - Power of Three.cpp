//#include <vector>
//
//class Solution 
//{
//public:
//	int maxCoins(std::vector<int>& nums) 
//	{
//
//	}
//};

/*


Power of Three


Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

@author Zixuan
@date	2016/5/29
*/

class Solution 
{
public:
	bool isPowerOfThree(int n) 
	{
		return n > 0 && 1162261467 % n == 0;//3^19=1162261467
	}
};

