/*


Balanced Binary Tree 


Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

@author Zixuan
@date	2015/8/19
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
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool isBalanced(TreeNode* root)
	{
		if (NULL == root)
			return true;
		vector<TreeNode*> v;

		int current = 0;
		v.push_back(root);
		
		while (current < v.size())
		{
			if (NULL != v[current]->left)
				v.push_back(v[current]->left);
			if (NULL != v[current]->right)
				v.push_back(v[current]->right);
			++current;
		}
			
		for (auto node : v)
			if (abs(depth(node->left) - depth(node->right)) > 1)
				return false;
    
		return true;
	}

private:
	int depth(TreeNode* node)
	{
		//In a recursive way.
		if (NULL == node)
			return 0;
		else if (NULL == node->left)
			return 1 + depth(node->right);
		else if (NULL == node->right)
			return 1 + depth(node->left);
		else
			return 1 + max(depth(node->left), depth(node->right));
	}
};