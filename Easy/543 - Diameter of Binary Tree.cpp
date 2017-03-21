/*


Diameter of Binary Tree


Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
Example:
Given a binary tree
	 1
	/ \
   2   3
  / \
 4   5

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
Note: The length of path between two nodes is represented by the number of edges between them.

@author Zixuan
@date	2017/3/21
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
#include <algorithm>

//Reference: https://discuss.leetcode.com/topic/83471/c-java-clean-code
class Solution 
{
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		auto diameter = 0;
		height(root, diameter);
		return diameter;
	}
private:
	int height(TreeNode* node, int& diameter) 
	{
		if (!node) 
			return 0;
		
		auto lh = height(node->left, diameter);
		auto rh = height(node->right, diameter);
		auto span = lh + rh;
		diameter = std::max(diameter, span);
		return 1 + std::max(lh, rh);
	}
};