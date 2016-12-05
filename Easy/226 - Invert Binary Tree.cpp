/*


Invert Binary Tree


Invert a binary tree.
	4
  /   \
 2     7
/ \   / \
1   3 6   9
to
	4
  /   \
 7     2
/ \   / \
9   6 3   1

@author Zixuan
@date	2016/12/5
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
	//Refence: https://discuss.leetcode.com/topic/16138/recursive-and-non-recursive-c-both-4ms/2
	TreeNode* invertTree(TreeNode* root) 
	{
		std::queue<TreeNode*> queue;
		if (!root)
			return nullptr;

		queue.push(root);

		while (!queue.empty())
		{
			auto now = queue.front();
			queue.pop();

			if (now) 
			{
				queue.push(now->left);
				queue.push(now->right);
				std::swap(now->left, now->right);
			}

			
		}

		return root;
	}
};