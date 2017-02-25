/*


Odd Even Linked List


Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.



Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

@author Zixuan
@date 2016/4/1
*/

#include <iostream>

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
	ListNode* oddEvenList(ListNode* head) 
	{
		if (!head)
			return nullptr;
		if (!head->next)
			return head;

		//At least two nodes.
		auto even_head = head->next;
		auto odd_tail = head;
		auto odd_even_flag = true;//Odd is true, even is false.
		auto current_node = head;

		while (current_node)
		{
			if (odd_even_flag)
				odd_tail = current_node;
			
			odd_even_flag = !odd_even_flag;

			auto temp = current_node->next;
			if (!temp)//Meet the end.
				break;
			current_node->next = temp->next;
			current_node = temp;
		}

		odd_tail->next = even_head;
		return head;
	}
};
