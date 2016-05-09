/*


Remove Duplicates from Sorted List II


Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

@author Zixuan
@date	2016/5/9
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
		if (!head || !head->next)
			return head;

		//Because the list is sorted, the duplicated ones must be neighbours.

		//Whether head is a duplicated one.
		auto dup_head = (head->val == head->next->val) ? true : false;
		auto last = head;

		//Remove duplicated head nodes.
		if (dup_head)
		{
			while (last->next)
			{
				if (head->val == last->next->val)
				{
					auto temp = last->next;
					last->next = temp->next;
					delete temp;
				}
				else
					break;
			}
		}

		while (true)
		{
			if (last->next && last->next->next && last->next->val == last->next->next->val)//Duplicated
			{
				auto value = last->next->val;
				while (last->next)
				{
					if (last->next->val == value)
					{
						auto temp = last->next;
						last->next = temp->next;
						delete temp;
					}
					else
						break;
				}
			}
			else if (last->next && last->next->next && last->next->val != last->next->next->val)
			{
				last = last->next;
			}
			else
				break;			
		}


		//Remove head if it is duplicated.
		if (dup_head)
		{
			auto temp = head;
			head = head->next;
			delete temp;
		}
		return head;
	}
};

