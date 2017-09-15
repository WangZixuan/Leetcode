/*


Find Bottom Left Tree Value


Given a binary tree, find the leftmost value in the last row of the tree.
Example 1:
	Input:

	 2
	/ \
   1   3

	Output:
	1

Example 2:
	Input:

		1
	   / \
	  2   3
	 /   / \
	4   5   6
   /
  7

	Output:
	7

@author Zixuan
@date	2017/9/15
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

#include <queue>
using namespace std;


class Solution 
{
public:
	int findBottomLeftValue(TreeNode* root) 
	{
		if (nullptr == root)
			return 0;

		queue<TreeNode*> nodes;
		queue<int> levels;

		auto currentLevel = 0;
		auto bottomLeft = root->val;
		nodes.push(root);
		levels.push(currentLevel);

		while (!nodes.empty())
		{
			auto thisLevel = levels.front() + 1;
			levels.pop();
			auto thisNode = nodes.front();
			nodes.pop();
			if (currentLevel<thisLevel)
			{
				currentLevel = thisLevel;
				bottomLeft = thisNode->val;
			}

			if (thisNode->left)
			{
				nodes.push(thisNode->left);
				levels.push(currentLevel);
			}

			if (thisNode->right)
			{
				nodes.push(thisNode->right);
				levels.push(currentLevel);
			}

		}

		return bottomLeft;

	}
};