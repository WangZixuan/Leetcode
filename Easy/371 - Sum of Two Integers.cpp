/*


Sum of Two Integers


Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

@author Zixuan
@date	2016/7/8
*/

class Solution 
{
public:
	//This is an amazing solutiuon!
	//Understand the reason!
	//https://discuss.leetcode.com/category/455/sum-of-two-integers
	//1.We can use a ^ b to get the bits of the sum without considering the carry bits.
	//2.We can get carry bits by using a & b like the operation above.
	//3.So it become the sub - problem.We need to calculate the sum of(a^b) and (a & b) << 1.
	//4.When the carry bits if zero, the function will return.

	int getSum(int a, int b) 
	{
 		if (a == 0) 
			return b;

		return getSum((a&b) << 1, a^b);
	}
};
