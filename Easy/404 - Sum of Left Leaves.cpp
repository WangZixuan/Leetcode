/*


Sum of Left Leaves 


Find the sum of all left leaves in a given binary tree.
Example:
	 3
	/ \
	9  20
	  /  \
	 15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

@author Zixuan
@date	2016/12/9
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

class Solution
{
public:
	//We use BFS.
	int sumOfLeftLeaves(TreeNode* root)
	{
		std::queue<TreeNode*> queue;
		if (!root)
			return 0;

		auto sum = 0;

		queue.push(root);

		while (!queue.empty())
		{
			auto now = queue.front();
			queue.pop();

			if (now)
			{
				queue.push(now->left);
				queue.push(now->right);
				if (now->left && !now->left->left && !now->left->right)
					sum += now->left->val;
			}


		}

		return sum;
	}
};