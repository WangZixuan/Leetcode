/*


Minimum Depth of Binary Tree


Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
#include <algorithm>
using namespace std;

class Solution
{
public:
	int minDepth(TreeNode* root)
	{
		//In a recursive way.
		if (NULL == root)
			return 0;
		else if (NULL == root->left && NULL != root->right)
			return 1 + minDepth(root->right);
		else if (NULL == root->right && NULL != root->left)
			return 1 + minDepth(root->left);
		else
			return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};
