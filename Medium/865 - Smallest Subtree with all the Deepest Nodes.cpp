/*


865 - Smallest Subtree with all the Deepest Nodes.cpp


Smallest Subtree with all the Deepest Nodes


Given the root of a binary tree, the depth of each node is the shortest distance to the root.
Return the smallest subtree such that it contains all the deepest nodes in the original tree.
A node is called the deepest if it has the largest depth possible among any node in the entire tree.
The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

Example 2:
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.

Example 3:
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.

Constraints:
The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.

@author Zixuan
@date	2026/1/9
*/

#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution 
{
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root)
	{
		if (root == nullptr)
			return root;

		unordered_map<TreeNode*, int> nodeToDepth;

		vector<TreeNode*> thisLevelNodes{ root };
		vector<TreeNode*> nextLevelNodes;
		
		// BFS
		int level = 1;
		while (thisLevelNodes.size() > 0)
		{
			for (auto& node : thisLevelNodes)
			{
				nodeToDepth[node] = level;
				if (node->left != nullptr)
					nextLevelNodes.push_back(node->left);
				if (node->right != nullptr)
					nextLevelNodes.push_back(node->right);
			}

			// If it reaches leaf level and only one leaf, return it
			// Because the answer is unique, so only one leaf can be returned, so later cases will not take leaf into consideration
			if (nextLevelNodes.size() == 0 && thisLevelNodes.size() == 1)
				return *thisLevelNodes.begin();

			++level;
			thisLevelNodes = move(nextLevelNodes);
		}

		--level; // Now we know how many levels in total

		unordered_map<TreeNode*, pair<int, int>> nodeToMaxDepth;
		dfs(root, nodeToMaxDepth, nodeToDepth); // Now we know what max level is for each node

		// Another BFS to get it
		TreeNode* curr = root;
		while (curr) 
		{
			int leftMax = nodeToMaxDepth[curr].first;
			int rightMax = nodeToMaxDepth[curr].second;

			if (leftMax == level && rightMax == level) {
				return curr;
			}
			if (leftMax == level) {
				curr = curr->left;
			}
			else if (rightMax == level) {
				curr = curr->right;
			}
			else {
				return curr;
			}
		}
		return curr;
	}

private:
	int dfs(TreeNode* node, unordered_map<TreeNode*, pair<int, int>>& nodeToMaxDepth, unordered_map<TreeNode*, int>& nodeToDepth)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			nodeToMaxDepth[node].first = nodeToDepth[node];
			nodeToMaxDepth[node].second = nodeToDepth[node];
		}
		else if (node->left == nullptr)
		{
			nodeToMaxDepth[node].first = nodeToDepth[node];
			nodeToMaxDepth[node].second = dfs(node->right, nodeToMaxDepth, nodeToDepth);
		}
		else if (node->right == nullptr)
		{
			nodeToMaxDepth[node].first = dfs(node->left, nodeToMaxDepth, nodeToDepth);
			nodeToMaxDepth[node].second = nodeToDepth[node];
		}
		else
		{
			nodeToMaxDepth[node].first = dfs(node->left, nodeToMaxDepth, nodeToDepth);
			nodeToMaxDepth[node].second = dfs(node->right, nodeToMaxDepth, nodeToDepth);
		}
		return max(nodeToMaxDepth[node].first, nodeToMaxDepth[node].second);
	}
};
