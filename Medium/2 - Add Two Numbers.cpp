/*


Add Two Numbers 


You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

@author Zixuan
@date	2015/8/21
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
        if (NULL == l1 && NULL == l2)
			return NULL;
		if (NULL == l1)
			return l2;
		if (NULL == l2)
			return l1;

		int value = l1->val + l2->val;
		ListNode* head = new ListNode(value % 10);
		value /= 10;

		ListNode* p =head;//Used to iterate.
		l1 = l1->next;
		l2 = l2->next;
		while (NULL != l1 && NULL != l2)
		{
			value += l1->val + l2->val;
			ListNode* ln = new ListNode(value % 10);
			p->next = ln;
			p =ln;
			value /= 10;

			l1 = l1->next;
			l2 = l2->next;
		}

		if (NULL == l1)
		{
			//All l2 left.
			while (1 == value && NULL != l2)
			{
				value += l2->val;
				ListNode* ln = new ListNode(value % 10);
				p->next = ln;
				p =ln;
				value /= 10;
				l2 = l2->next;
			}

			//Deal with some special cases.
			if (0 == value && NULL != l2)
				p->next = l2;//Make a trick... 
							 //It may cause trouble when deleting the returned value,
							 //because it deletes part of l2 as well.
			else if (1 == value && NULL == l2)
			{
				ListNode* ln = new ListNode(1);
				p->next = ln;
			}
		}
		else if (NULL == l2)
		{
			//All l1 left.
			while (1 == value && NULL != l1)
			{
				value += l1->val;
				ListNode* ln = new ListNode(value % 10);
				p->next = ln;
				p =ln;
				value /= 10;
				l1 = l1->next;
			}

			//Deal with some special cases.
			if (0 == value && NULL != l1)
				p->next = l1;//Make this trick again... 
							 //It may cause trouble when deleting the returned value,
							 //because it deletes part of l1 as well.
			else if (1 == value && NULL == l1)
			{
				ListNode* ln = new ListNode(1);
				p->next = ln;
			}
		}
	
		return head;
    }
};
