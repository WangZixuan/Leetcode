/*


Binary Tree Level Order Traversal 


Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

@author Zixuan
@date 2015/8/18
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
    vector<vector<int>> levelOrder(TreeNode* root) 
	{
        vector<vector<int>> outsideVector;

		if (NULL == root)
			return outsideVector;

		vector<int> insideVector;
		vector<TreeNode*> evenNodeVector;
		vector<TreeNode*> oddNodeVector;

		//Root level.
		insideVector.push_back(root->val);
		outsideVector.push_back(insideVector);
		evenNodeVector.push_back(root);

		while (!(evenNodeVector.empty() && oddNodeVector.empty()))
		{
			insideVector.clear();
			if (!evenNodeVector.empty())
			{	
				//evenNodeVector stores infomation now.
				for (auto node : evenNodeVector)
				{
					if (NULL != node->left)
					{
						oddNodeVector.push_back(node->left);
						insideVector.push_back(node->left->val);
					}
					if(NULL != node->right)
					{
						oddNodeVector.push_back(node->right);
						insideVector.push_back(node->right->val);
					}
				}
				evenNodeVector.clear();
			}
			else
			{
				//oddNodeVector stores infomation now.
				for (auto node : oddNodeVector)
				{
					if (NULL != node->left)
					{
						evenNodeVector.push_back(node->left);
						insideVector.push_back(node->left->val);
					}
					if(NULL != node->right)
					{
						evenNodeVector.push_back(node->right);
						insideVector.push_back(node->right->val);
					}
				}
				oddNodeVector.clear();
			}
			if (!insideVector.empty())
				outsideVector.push_back(insideVector);
		}

		return outsideVector;
    }
};
