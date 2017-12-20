/*


Find Duplicate Subtrees


Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with same node values.
Example 1:
		  1
		 / \
		2   3
	   /   / \
	  4   2   4
	 /
	4
The following are two duplicate subtrees:
	  2
	 /
	4
and
	4

@author Zixuan
@date	2017/12/20
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

#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
	{
		collect(root);
		return duplicatesNodes;
	}

private:
	map<string, int> duplicatesStrings;
	vector<TreeNode*> duplicatesNodes;

	string collect(TreeNode* root)
	{
		if (!root)
			return "#";

		auto str = to_string(root->val) + "," + collect(root->left) + "," + collect(root->right);

		++duplicatesStrings[str];

		if (2 == duplicatesStrings[str])
			duplicatesNodes.push_back(root);

		return str;
	}
};