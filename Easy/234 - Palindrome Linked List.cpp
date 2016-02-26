/*


Palindrome Linked List


Given a singly linked list, determine if it is a palindrome.

@author Zixuan
@date	2016/2/25
*/

//in O(n) time and O(1) space

struct PalindromeHead
{
	ListNode* left;
	ListNode* right;
};

class Solution 
{
public:
	bool isPalindrome(ListNode* head) 
	{
		if (nullptr == head)
			return true;

		auto count = 0;//Used to record the number of the nodes.
		auto p = head;
		while(nullptr != p)//In O(n) time.
		{
			++count;
			p = p->next;
		}

		if (1 == count)
			return true;

		p = head;
		auto q = p->next;

		for (auto i = 0; i < (count - 1) / 2; ++i)
		{
			auto temp = q->next;
			q->next = p;
			p = q;
			q = temp;
		}
		
		auto pHead = new PalindromeHead();
		if (0 == count % 2)
			pHead->left = p;
		else
			pHead->left = p->next;
		pHead->right = q;

		head->next = nullptr;//Without this line, the OJ said it was Time Limit Exceeded.//WHY?

		while (pHead->right)//In O(n) time.
		{
			if (pHead->left->val != pHead->right->val)
			{
				delete pHead;
				return false;
			}
			
			//else
			pHead->left = pHead->left->next;
			pHead->right = pHead->right->next;
		}

		delete pHead;
		return true;
	}
};
