/*


Swap Nodes in Pairs


Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

@author Zixuan
@date	2016/11/27
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	ListNode* swapPairs(ListNode* head) 
	{
		if (!head || !head->next)
			return head;

		//At least two nodes now.
		//Change head.
		auto p = head;
		head = head->next;
		p->next = head->next;
		head->next = p;
		
		while (p->next)
		{
			//Break when only one node left.
			if (!p->next->next)
				break;

			auto q = p->next; 
			p->next = q->next;
			q->next = p->next->next;
			p->next->next = q;
			p = q;
		}
		return head;
	}
};