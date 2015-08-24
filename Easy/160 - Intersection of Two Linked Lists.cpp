﻿/*


Intersection of Two Linked Lists 


Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

@author Zixuan
@date	2015/8/24
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
        //See http://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

		if (NULL == headA || NULL == headB)
			return NULL;
		
		int numA = 0, numB = 0;

		ListNode* tempA = headA, * tempB = headB;
		while (NULL != tempA)
		{
			tempA = tempA->next;
			++numA;
		}
		while (NULL != tempB)
		{
			tempB = tempB->next;
			++numB;
		}

		tempA = headA;
		tempB = headB;

		if (numA < numB)
		{
			int difference = numB - numA;
			while (difference-- > 0)
				tempB =tempB->next;
		}
		else if (numA > numB)
		{
			int difference = numA - numB;
			while (difference-- > 0)
				tempA =tempA->next;
		}

		//Now they start iterating synchronously.
		while (NULL != tempA)
		{
			if (tempA == tempB)
				return tempA;
			else
			{
				tempA = tempA->next;
				tempB = tempB->next;
			}
		}
		
		return NULL;

    }
};
