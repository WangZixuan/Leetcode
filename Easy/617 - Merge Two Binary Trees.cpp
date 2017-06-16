/*


Merge Two Binary Trees


Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
Example 1:
	Input:
	Tree 1                     Tree 2
	   1                         2
	  / \                       / \
	 3   2                     1   3
	/                           \   \
	5                             4   7
	Output:
	Merged tree:
	   3
	  / \
	 4   5
	/ \   \
	5   4   7

Note: The merging process must start from the root nodes of both trees.

@author Zixuan
@date 2017/6/16
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

class Solution 
{
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
	{
		if (nullptr == t1)
			return t2;
		if (nullptr == t2)
			return t1;

		t1->val += t2->val;

		//Both have no children
		if (!t1->left&&!t1->right&&!t2->left&&!t2->right)
			return t1;

		
		//Only one child of two nodes
		if (!t1->left&&!t1->right&&!t2->left&&t2->right)
		{
			t1->right = t2->right;
			return t1;
		}

		if (!t1->left&&!t1->right&&t2->left&&!t2->right)
		{
			t1->left = t2->left;
			return t1;
		}

		if (!t1->left&&t1->right&&!t2->left&&!t2->right)
			return t1;

		if (t1->left&&!t1->right&&!t2->left&&!t2->right)
			return t1;


		//Each node has one child
		if (t1->left&&!t1->right&&t2->left&&!t2->right)
		{
			t1->left= mergeTrees(t1->left, t2->left);
			return t1;
		}
		if (!t1->left&&t1->right&&!t2->left&&t2->right)
		{
			t1->right= mergeTrees(t1->right, t2->right);
			return t1;
		}
		
		if (t1->left&&!t1->right&&!t2->left&&t2->right)
		{
			t1->right = t2->right;
			return t1;
		}
		if (!t1->left&&t1->right&&t2->left&&!t2->right)
		{
			t1->left = t2->left;
			return t1;
		}

		//One has no children
		if (t1->left&&t1->right&&!t2->left&&!t2->right)
			return t1;
		if (!t1->left&&!t1->right&&t2->left&&t2->right)
		{
			t1->left = t2->left;
			t1->right = t2->right;
			return t1; 
		}


		//Three children of two nodes
		if (t1->left&&t1->right&&t2->left&&!t2->right)
		{
			t1->left = mergeTrees(t1->left, t2->left);
			return t1;
		}
		if (t1->left&&t1->right&&!t2->left&&t2->right)
		{
			t1->right = mergeTrees(t1->right, t2->right);
			return t1;
		}
		if (t1->left&&!t1->right&&t2->left&&t2->right)
		{
			t1->right = t2->right;
			t1->left = mergeTrees(t1->left, t2->left);
			return t1;
		}
		if (!t1->left&&t1->right&&t2->left&&t2->right)
		{
			t1->left = t2->left;
			t1->right = mergeTrees(t1->right, t2->right);
			return t1;
		}

		//Four children
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};