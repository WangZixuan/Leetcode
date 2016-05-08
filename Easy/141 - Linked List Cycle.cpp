#include <iostream>

/*


Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

@author Zixuan
@date	2016/5/8
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution 
{
public:
	bool hasCycle(ListNode* head) 
	{
		//Because we want the solution without extra space,
		//we will change every node value once meet.
		
		//So long time has passed that I forgot this...
		if (!head)
			return false;

		while (head->next)
		{
			if (INT_MIN == head->val)
				return true;
			head->val = INT_MIN;
			head = head->next;
		}
		return false;
	}
};
