/*


Maximum Depth of Binary Tree 


Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
#include <iostream>
#include <stack>
using namespace std;

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
	{
		//In a recursive way.
		//ACCEPTED!!!
		/*
		if (NULL == root)
			return 0;
		else if (NULL == root->left)
			return 1 + maxDepth(root->right);
		else if (NULL == root->right)
			return 1 + maxDepth(root->left);
		else
			return 1 + max(maxDepth(root->left), maxDepth(root->right));
		*/

		//In an iterative way, based on pre-order.		
		struct NodeLevel
		{
			TreeNode* node;
			int level;
		};

		if (NULL == root)
			return 0;

		int maxDepthSofar = INT_MIN;
		stack<NodeLevel> s;
		NodeLevel nl;
		nl.node = root;
		nl.level = 1;
		s.push(nl);

		while (!s.empty())
		{
			NodeLevel nlTemp = s.top();
			s.pop();

			if (NULL != nlTemp.node->left)
			{
				nl.node =  nlTemp.node->left;
				nl.level = nlTemp.level + 1;
				s.push(nl);
			}

			if (NULL != nlTemp.node->right)
			{
				nl.node =  nlTemp.node->right;
				nl.level = nlTemp.level + 1;
				s.push(nl);
			}

			if (nl.level > maxDepthSofar)
				maxDepthSofar = nl.level;
		}

		return maxDepthSofar;
		
    }
};