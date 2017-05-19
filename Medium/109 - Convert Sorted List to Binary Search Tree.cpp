/*


Convert Sorted List to Binary Search Tree


Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

@author Zixuan
@date	2017/5/19
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include <vector>
using namespace std;

class Solution 
{
public:
	TreeNode* sortedListToBST(ListNode* head) 
	{
		if (!head)
			return nullptr;

		while (head)
		{
			data.push_back(head->val);
			head = head->next;
		}

		//Now we deal with vector data.
		//Binary search and insert into the tree.
		return binaryInsert(0, data.size() - 1);
	}

private:
	TreeNode* binaryInsert(int start, int end)
	{
		if (start<0 || end >= data.size() || start > end)
			return nullptr;

		if (start == end)
		{
			auto node = new TreeNode(data[start]);
			return node;
		}

		auto index = (start + end) / 2;
		auto node = new TreeNode(data[index]);
		node->left = binaryInsert(start, index - 1);
		node->right = binaryInsert(index + 1, end);
		return node;
	}

	vector<int> data;//Store list node data to a vector.

};
