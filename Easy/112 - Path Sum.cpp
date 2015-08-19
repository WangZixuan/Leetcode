/*


Path Sum Total 


Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
using namespace std;

class Solution 
{
public:
    bool hasPathSum(TreeNode* root, int sum)
	{
        if (NULL == root)
			return false;
		if (sum == root->val && NULL == root->left && NULL == root->right)
			return true;

		//if (NULL == root->left)
		//	return hasPathSum(root->right, sum - root->val);
		//
		//if (NULL == root->right)
		//	return hasPathSum(root->left, sum - root->val);

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};