/*


Remove Linked List Elements


Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

@author Zixuan
@date	2015/11/22
*/

/**
* Definition for singly-linked list.
* struct ListNode 
* {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution 
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		//First things first, return NULL if head is this linked list is NULL!!!
		if (NULL == head)
			return NULL;
		
		//Then remove all nodes of val in the start.
		ListNode* current = head;
		while (val == current->val)
		{
			//What if this linked list is empty?
			if (NULL != head->next)
			{
				head = head->next;
				delete current;
				current = head;
			}
			else
				return NULL;
		}

		//Next, val is in the middle or last.
		ListNode* prev = head;
		if (NULL != head->next)
			current = current->next;
		else
			return head;

		while (NULL != current)
		{
			if (val == current->val)
			{
				prev->next = current->next;
				delete current;
				current = prev->next;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}

		return head;
	}
};