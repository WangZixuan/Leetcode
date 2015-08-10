/*


Merge Two Sorted Lists


Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

@author Zixuan
@date	2015/8/10
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
        if (NULL == l1 && NULL == l2)
			return NULL;
		else if (NULL == l1 || NULL == l2)
			return (NULL == l1) ? l2 : l1;

		ListNode* head, * tail;

		if (l1->val < l2->val)
		{
			head = tail = l1;
			l1 = l1->next;
		}
		else
		{
			head = tail = l2;
			l2 = l2->next;
		}

		while (NULL != l1 && NULL != l2)
		{
			if (l1->val < l2->val)
			{
				tail->next = l1;
				tail = l1;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				tail = l2;
				l2 = l2->next;
			}
		}

		//Append the rest to the merged list.
		tail->next = (NULL == l1) ? l2 : l1;

		return head;
    }
};
