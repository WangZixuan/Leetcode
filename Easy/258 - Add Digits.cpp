/*


Add Digits
 

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit. 

For example: 

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it. 

Follow up:
 Could you do it without any loop/recursion in O(1) runtime? 

Hint:
1.A naive implementation of the above process is trivial. Could you come up with other methods? 
2.What are all the possible results?
3.How do they occur, periodically or randomly?
4.You may find this Wikipedia article(https://en.wikipedia.org/wiki/Digital_root) useful.

@author Zixuan
@date	2016/5/10
*/

class Solution 
{
public:
	int addDigits(int num) 
	{
		//See https://en.wikipedia.org/wiki/Digital_root.
		return num - 9 * ((num - 1) / 9);
	}
};