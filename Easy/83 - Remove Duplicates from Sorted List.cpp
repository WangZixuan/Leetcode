/*


Remove Duplicates from Sorted List 


Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

@author Zixuan
@date 	2015/8/12
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
    ListNode* deleteDuplicates(ListNode* head) 
	{
		if (!head)
			return head;

		ListNode* pos1 = head;
		ListNode* pos2 = head->next;
		while (NULL != pos2)
		{
			if (pos1->val != pos2->val)
			{
				pos1 = pos2;//I assume it faster than pos1 = pos1->next.
				pos2 = pos1->next;
			}
			else
			{
				pos2 = pos2->next;
				delete pos1->next;
				pos1->next = pos2;
			}
		}

		return head;
    }
};
