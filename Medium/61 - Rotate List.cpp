/*


Rotate List


Given a list, rotate the list to the right by k places, where k is non-negative.

Example:
Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.

@author Zixuan
@date	2017/12/18
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
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (!head)
			return nullptr;

		auto length = 1;
		auto h = head;
		while (h->next)
		{
			++length;
			h = h->next;
		}

		k = length - k%length;

		h->next = head;

		while (k > 1)
		{
			head = head->next;
			--k;
		}
		auto temp = head->next;
		head->next = nullptr;
		return temp;

	}
};
