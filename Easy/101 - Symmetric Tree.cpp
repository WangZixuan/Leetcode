/*


Symmetric Tree


Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

  1
 / \
2   2
 \   \
  3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

@author Zixuan
@date	2017/10/24
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
	bool isSymmetric(TreeNode* root)
	{
		//Only one mirror: in the middle, no mirror in the middle of a subtree.
		if (!root || !root->left && !root->right)
			return true;
		if (!root->left || !root->right)
			return false;

		if (root->left->val != root->right->val)
			return false;

		queue<TreeNode*> left;
		queue<TreeNode*> right;

		left.push(root->left);
		right.push(root->right);

		while (!left.empty())
		{
			auto lv = left.front();
			auto rv = right.front();

			if (lv->left && !rv->right || !lv->left && rv->right || lv->left && rv->right && lv->left->val != rv->right->val)
				return false;

			if (lv->right && !rv->left || !lv->right && rv->left || lv->right && rv->left && lv->right->val != rv->left->val)
				return false;

			if (lv->left)
				left.push(lv->left);
			if (lv->right)
				left.push(lv->right);

			if (rv->right)
				right.push(rv->right);
			if (rv->left)
				right.push(rv->left);


			left.pop();
			right.pop();
		}


		return true;
	}
};
