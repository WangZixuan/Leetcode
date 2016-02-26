/*


Lowest Common Ancestor of a Binary Search Tree


Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±
		_______6______
		/              \
	___2__          ___8__
	/      \        /      \
	0      _4       7       9
		  /  \
		  3   5


For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

@author Zixuan
@date 2016/2/26
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		auto pathToP = searchNodeOnValue(root, p->val);
		auto pathToQ = searchNodeOnValue(root, q->val);

		if (0 == pathToP.size() || 0 == pathToQ.size())
			return root;

		auto pointer = root;

		auto index = 0;
		while (index < min(pathToP.size(), pathToQ.size()))
		{
			if (pathToP[index] == pathToQ[index] && pathToQ[index] == 0)
				pointer = pointer->left;
			else if (pathToP[index] == pathToQ[index] && pathToQ[index] == 1)
				pointer = pointer->right;
			else//Not equal.
				break;

			++index;
		}
		return pointer;
	}

private:
	vector<int> searchNodeOnValue(TreeNode* root, int value)
	{
		vector<int> path;

		auto p = root;
		while (p->val != value)
		{
			if (p->val > value)
			{
				p = p->left;
				path.push_back(0);
			}
			else
			{
				p = p->right;
				path.push_back(1);
			}
		}
		return path;
	}

	
};
