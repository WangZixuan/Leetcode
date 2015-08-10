/*


Remove Nth Node From End of List


Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list : 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.


Note :
	Given n will always be valid.
	Try to do this in one pass.

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
#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		if (NULL == head || n < 0)
			return NULL;

		//In order to do it in one run, we will have to store all nodes in a vector.
		vector<ListNode*> v;

		ListNode* temp = head;
		while (NULL != temp)
		{
			v.push_back(temp);
			temp = temp->next;
		}

		//Now get the node.
		if (v.size() == n)//Delete the first
		{
			head = head->next;
			delete v[0];
		}
		else if (1 == n)//Delete the last.
		{
			v[v.size() - n - 1]->next = NULL;
			delete v[v.size() - n];
		}
		else
		{
			v[v.size() - n - 1]->next = v[v.size() - n + 1];
			delete v[v.size() - n];
		}

		return head;
	}
};