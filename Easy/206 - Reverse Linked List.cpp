/*


Reverse Linked List


Reverse a singly linked list.

@author Zixuan
@date	2015/11/30
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
	ListNode* reverseList(ListNode* head) 
	{
		if (NULL == head || NULL == head->next)
			return head;

		ListNode* a = head;
		ListNode* b = head->next;

		if (NULL == b->next)
		{
			b->next = a;
			a->next = NULL;
			return b;
		}

		ListNode* c = b->next;
		head->next = NULL;
		while (NULL != c)
		{
			b->next = a;
			a = b;
			b = c;
			c = c->next;
		}
		b->next = a;

		return b;
	}
};
